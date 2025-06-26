#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int map[100][100];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin >> map[i][j];
    
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<pair<int,int>> teduri;
    int time = 0;
    int cnt = 0;
    // 첫 테두리는 map의 테두리 bfs 시작
    // for(int i=0;i<n;i++)
    // for(int j=0;j<m;j++)
    //     if(i==0 || j==0 || i==n-1 || j==m-1)
    //         teduri.push_back({i,j});
    teduri.push_back({0,0});
    while(true) {
        // 이전 치즈 테두리에서 bfs 시작
        int limit = teduri.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<limit;i++) {
            int x = teduri.back().first;
            int y = teduri.back().second;
            temp.push_back(teduri.back());
            teduri.pop_back();
            q.push({x,y});
            if(!visited[x][y]) {
                visited[x][y] = true;
                cnt++;
            }
        }
        // 치즈인곳 vector에 저장, 도달한 곳 갯수 세기
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            if(map[x][y] == 1) {
                teduri.push_back({x,y});
                continue;
            }

            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
                q.push({nx,ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
        // 도달한 곳 갯수가 n*m 이면 현재 시간+1과 치즈인곳 vector 크기 출력하고 끝내기
        // 아니면 치즈인곳 vector 순회하며 0으로 바꾸고 시간++
        if(cnt == n*m) {
            if(teduri.size() == 0) {
                cout << time <<'\n';
                cout << temp.size() << '\n';
                return 0;
            }
            cout << time+1 <<'\n';
            cout << teduri.size() << '\n';
            return 0;
        } else {
            for(auto& te : teduri) {
                map[te.first][te.second] = 0;
            }
            time++;
        }
    }
}


// 첫번째 시도 시간초과.
// 모든 시간마다 테두리에서 시작했는데
// 그럴 필요 없이 매 시간마다 이전 테두리에서 시작하자