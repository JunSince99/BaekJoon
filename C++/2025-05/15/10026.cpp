#include <iostream>
#include <vector>
#include <queue>

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> paint(N);
    vector<string> rgpaint(N);
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    vector<vector<bool>> rgvisited(N,vector<bool>(N,false));
    for(int i=0;i<N;i++) {
        cin >> paint[i];
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(paint[i][j] == 'G') {
                rgpaint[i] += 'R';
            } else {
                rgpaint[i] += paint[i][j];
            }
        }
    }

    queue<pair<int,int>> q;
    queue<pair<int,int>> rgq;
    int area = 0;
    int rgarea = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {

            if(!visited[i][j]) {
                q.push({i,j});
                visited[i][j] = true;
                area += 1;
            }

            while(!q.empty()) {
                pair<int,int> cur = q.front();
                q.pop();

                for(int k=0;k<4;k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(0<=nx && nx<N && 0<=ny && ny<N && !visited[nx][ny] && paint[i][j] == paint[nx][ny]) {
                        q.push({nx,ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            if(!rgvisited[i][j]) {
                rgq.push({i,j});
                rgvisited[i][j] = true;
                rgarea += 1;
            }

            while(!rgq.empty()) {
                pair<int,int> cur = rgq.front();
                rgq.pop();

                for(int k=0;k<4;k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(0<=nx && nx<N && 0<=ny && ny<N && !rgvisited[nx][ny] && rgpaint[i][j] == rgpaint[nx][ny]) {
                        rgq.push({nx,ny});
                        rgvisited[nx][ny] = true;
                    }
                }
            }
        }
    }

    cout << area << ' ' << rgarea << '\n';

    return 0;
}