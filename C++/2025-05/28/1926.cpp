#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> maps(n,vector<int>(m));
    vector<vector<bool>> visited(n,vector<bool>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 0) {
                visited[i][j] = true;
            }
        }
    }

    int maxNB = 0;
    int countpaint = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j]) {
                countpaint++;
                queue<pair<int,int>> q;
                int nb = 1;
                q.push({i,j});
                visited[i][j] = true;

                while(!q.empty()) {
                    int curx = q.front().first;
                    int cury = q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++) {
                        int nx = curx + dx[k];
                        int ny = cury + dy[k];

                        if(0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny]) {
                            q.push({nx,ny});
                            visited[nx][ny] = true;
                            nb++;
                        }
                    }
                }
                maxNB = max(maxNB, nb);
            }
        }
    }

    cout << countpaint << '\n';
    cout << maxNB << '\n';
}