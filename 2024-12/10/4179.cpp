#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int nx[4] = {1,-1,0,0};
int ny[4] = {0,0,1,-1};

struct Obje{
    char who;
    int x,y,time;
};

queue<Obje> q;

int FastestTime(vector<vector<char>>& maze, int R, int C) {
    while(!q.empty()) {
        Obje cur = q.front();
        q.pop();
        if (cur.who == 'F') {
            for (int i=0; i<4;i++){
                int dx = cur.x + nx[i];
                int dy = cur.y + ny[i];
                if (0<=dx && dx<R && 0<=dy && dy<C && (maze[dx][dy] == '.' || maze[dx][dy] == 'J')) {
                    maze[dx][dy] = 'F';
                    q.push({'F',dx,dy,cur.time+1});
                }
            }
        } else if (cur.who == 'J') {
            for (int i=0; i<4;i++){
                int dx = cur.x + nx[i];
                int dy = cur.y + ny[i];
                if (dx == -1 || dx == R || dy == -1 || dy == C) {
                    return cur.time + 1;
                } else if (0<=dx && dx<R && 0<=dy && dy<C && maze[dx][dy] == '.') {
                    maze[dx][dy] = 'J';
                    q.push({'J',dx,dy,cur.time+1});
                }
            }
        }
    }
    return -1;
}

int main() {
    int R,C;
    cin >> R >> C;
    vector<vector<char>> maze(R,vector<char>(C));
    Obje startJi = {'J',0,0,0};
    Obje startFi = {'F',0,0,0};

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'J') {
                startJi.x = i;
                startJi.y = j;
            } else if(maze[i][j] == 'F') {
                startFi.x = i;
                startFi.y = j;
                q.push(startFi);
            }
        }
    }
    q.push(startJi);
    int answer = FastestTime(maze,R,C);
    if (answer == -1) cout << "IMPOSSIBLE" << endl;
    else if(answer >= 0) cout << answer << endl;

    return 0;
}