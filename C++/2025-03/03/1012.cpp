#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int M,N,K;
        cin >> M >> N >> K;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<vector<bool>> cab(N, vector<bool>(M, false));
        for(int k=0; k<K;k++) {
            int x,y;
            cin >> x >> y;
            cab[y][x] = true;
        }
        int jirung = 0;
        for(int n=0;n<N;n++) {
            for(int m=0; m<M; m++) {
                if (!visited[n][m] && cab[n][m]) {
                    jirung++;
                    queue<pair<int,int>> q;
                    q.push({n,m});
                    visited[n][m] = true;
                    while(!q.empty()){
                        pair<int,int> cur = q.front();
                        q.pop();

                        for(int i=0;i<4;i++) {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];

                            if(0<=nx && nx<N && 0<=ny && ny<M && !visited[nx][ny] && cab[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                } else {
                    visited[n][m] = true;
                }
            }
        }

        cout << jirung << '\n';
    }
    return 0;
}