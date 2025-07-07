#include <iostream>
#include <queue>
using namespace std;

int cheese;
int n,m;
int maps[100][100];
int visited[100][100];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 1) cheese++;
        }
    }
    int time = 0;
    queue<pair<int,int>> start;
    start.push({0,0});
    visited[0][0] = 1;
    while(cheese) { // 다 돌아서 녹일 치즈 저장
        time++;

        queue<pair<int,int>> q;
        while(!start.empty()) { // 시작점 갱신
            auto cur = start.front(); start.pop();
            maps[cur.first][cur.second] = 0;
            q.push(cur);
        }

        while(!q.empty()) {
            auto cur = q.front(); q.pop();

            for(int i=0;i<4;i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(!visited[nx][ny] && maps[nx][ny] == 0) {
                    q.push({nx,ny});
                    visited[nx][ny]++;
                } else if (maps[nx][ny] == 1) { // 사방 확인 후 녹으면 start에 저장, 치즈-1, visited
                    if(visited[nx][ny]==1) {
                        start.push({nx,ny});
                        cheese--;
                        visited[nx][ny]++;
                    } else {
                        visited[nx][ny]++;
                    }
                }
            }
        }
    }

    cout << time;
}