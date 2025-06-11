#include <iostream>
#include <queue>
using namespace std;

int T;
int w,h;
char maps[1001][1001];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct qvar {
    int x;
    int y;
    int time;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        int Sx, Sy;
        queue<qvar> q;
        cin >> w >> h;
        for(int i=0;i<h;i++) { // 맵 입력
            string temp;
            cin >> temp;
            for(int j=0;j<w;j++) {
                maps[i][j] = temp[j];
                if(maps[i][j] == '*') {
                    q.push({i,j,-1});
                } else if(maps[i][j] == '@') {
                    Sx = i;
                    Sy = j;
                }
            }
        }
        bool escape = false;
        q.push({Sx,Sy,0});
        while(!q.empty()) {
            qvar cur = q.front();
            q.pop();
            
            if(cur.time == -1) {
                for(int i=0;i<4;i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if(0<=nx && nx<h && 0<=ny && ny<w && (maps[nx][ny] == '.' || maps[nx][ny] == '@')) {
                        maps[nx][ny] = '*';
                        q.push({nx,ny,-1});
                    }
                }    
            } else {
                for(int i=0;i<4;i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if(nx<0 || nx>=h || ny<0 || ny>=w) {
                        escape = true;
                        break;
                    }
                    if(maps[nx][ny] == '.') {
                        q.push({nx,ny,cur.time+1});
                        maps[nx][ny] = '@';
                    }
                }
            }
            if(escape) {
                cout << cur.time+1 << '\n';
                break;
            }
        }
        if(!escape) cout << "IMPOSSIBLE" << '\n';
    }
}