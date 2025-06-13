#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M,K;
int maps[1000][1000];
bool visited[11][1000][1000];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct locate {
    int x;
    int y;
    int power;
    int time;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<M;j++) {
            maps[i][j] = temp[j] - '0';
        }
    }
    
    queue<locate> q;
    q.push({0,0,K,1});
    visited[K][0][0] = true;
    while(!q.empty()) {
        locate cur = q.front();
        q.pop();

        if(cur.x == N-1 && cur.y == M-1) {
            cout << cur.time << '\n';
            return 0;
        }

        for(int i=0;i<4;i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(cur.power > 0) {
                if(0<=nx && nx<N && 0<=ny && ny<M) {
                    if (maps[nx][ny] == 0 && !visited[cur.power][nx][ny]) {
                        q.push({nx,ny,cur.power,cur.time+1});
                        visited[cur.power][nx][ny] = true;
                    } else if(maps[nx][ny] == 1 && !visited[cur.power-1][nx][ny]) {
                        if (cur.time % 2 != 0) {
                            q.push({nx,ny,cur.power-1,cur.time+1});
                            visited[cur.power-1][nx][ny] = true;
                        } else {
                            q.push({cur.x,cur.y,cur.power,cur.time+1});
                        }
                        
                    }
                    
                }
            } else {
                if(0<=nx && nx<N && 0<=ny && ny<M && !visited[0][nx][ny] && maps[nx][ny] == 0) {
                    q.push({nx,ny,cur.power,cur.time+1});
                    visited[0][nx][ny] = true;
                }
            }
        }
    }
    cout << -1 << '\n';
}