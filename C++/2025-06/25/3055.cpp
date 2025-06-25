#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int R, C;
char maps[50][50];
bool visited[50][50];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct movers{
    int x,y,time;
    bool iswater;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    movers go;

    cin >> R >> C;
    queue<movers> q;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> maps[i][j];
            if(maps[i][j] == '*') q.push({i,j,0,true});
            else if(maps[i][j] == 'S') go = {i,j,0,false};
        }
    }
    q.push(go);
    visited[go.x][go.y] = true;
    maps[go.x][go.y] = '.';
    while(!q.empty()) {
        movers cur = q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
            if(!cur.iswater && maps[nx][ny] == 'D') {
                cout << cur.time + 1 << '\n';
                return 0;
            }
            if(maps[nx][ny] != '.') continue;

            if(cur.iswater) {
                maps[nx][ny] = '*';
                q.push({nx,ny,cur.time+1,true});
            } else if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx,ny,cur.time+1,false});
            }
        }
    }
    cout << "KAKTUS" << '\n';
}