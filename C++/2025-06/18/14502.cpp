#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ans;
int n,m;
int maps[8][8];
vector<pair<int,int>> two;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int zero = n * m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> maps[i][j];
            if(maps[i][j] == 1) {
                zero--;
            } else if(maps[i][j] == 2) {
                zero--;
                two.push_back({i,j});
            }
        }
    }

    for(int i=0;i<m*n-2;i++) {
        for(int j=i+1;j<m*n-1;j++) {
            for(int k=j+1;k<m*n;k++) {
                pair<int,int> a = {i/m, i%m};
                pair<int,int> b = {j/m, j%m};
                pair<int,int> c = {k/m, k%m};
                int cnt = zero;
                if(maps[a.first][a.second] == 0 && maps[b.first][b.second] == 0 && maps[c.first][c.second] == 0) {
                    cnt -= 3;
                    queue<pair<int,int>> q;
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                    // a,b,c 방문처리
                    visited[a.first][a.second] = true;
                    visited[b.first][b.second] = true;
                    visited[c.first][c.second] = true;
                    // two 순회하며 큐에 추가
                    for(pair<int,int> t : two)
                        q.push({t.first,t.second});
                    // 0이고 방문하지 않은 경우에만 큐에 추가
                    // 방문할 때마다 cnt;
                    while(!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();

                        for(int d=0;d<4;d++) {
                            int nx = cur.first + dx[d];
                            int ny = cur.second + dy[d];

                            if(0<=nx && nx<n && 0<=ny && ny<m && maps[nx][ny] == 0 && !visited[nx][ny]) {
                                q.push({nx,ny});
                                visited[nx][ny] = true;
                                cnt--;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout << ans;
}