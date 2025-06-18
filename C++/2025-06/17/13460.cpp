#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
char maps[10][10];
bool visited[10][10][10][10];

struct rblo{
    int rx;
    int ry;
    int bx;
    int by;
    int time;
};

rblo up(rblo cur) {
    cur.time += 1;
    int nx = -1;
    bool Bfirst = false;
    while(maps[cur.rx+nx][cur.ry] != '#') {
        cur.rx += nx;
        if(maps[cur.rx][cur.ry] == 'O') break;
        if(cur.rx == cur.bx && cur.ry == cur.by) Bfirst = true;
    }
    while(maps[cur.bx+nx][cur.by] != '#') {
        cur.bx += nx;
        if(maps[cur.bx][cur.by] == 'O') break;
    }

    // 겹침 처리만 하면 되는거 아닌가? 둘 다 O일 경우만 빼고.
    if(cur.rx == cur.bx && cur.ry == cur.by) {
        if(maps[cur.rx][cur.ry] == 'O') return cur;

        if(Bfirst) cur.rx++;
        else cur.bx++;
    }

    return cur;
}

rblo down(rblo cur) {
    cur.time += 1;
    int nx = 1;
    bool Bfirst = false;
    while(maps[cur.rx+nx][cur.ry] != '#') {
        cur.rx += nx;
        if(maps[cur.rx][cur.ry] == 'O') break;
        if(cur.rx == cur.bx && cur.ry == cur.by) Bfirst = true;
    }
    while(maps[cur.bx+nx][cur.by] != '#') {
        cur.bx += nx;
        if(maps[cur.bx][cur.by] == 'O') break;
    }

    // 겹침 처리만 하면 되는거 아닌가? 둘 다 O일 경우만 빼고.
    if(cur.rx == cur.bx && cur.ry == cur.by) {
        if(maps[cur.rx][cur.ry] == 'O') return cur;

        if(Bfirst) cur.rx--;
        else cur.bx--;
    }

    return cur;
}

rblo left(rblo cur) {
    cur.time += 1;
    int ny = -1;
    bool Bfirst = false;
    while(maps[cur.rx][cur.ry+ny] != '#') {
        cur.ry += ny;
        if(maps[cur.rx][cur.ry] == 'O') break;
        if(cur.rx == cur.bx && cur.ry == cur.by) Bfirst = true;
    }
    while(maps[cur.bx][cur.by+ny] != '#') {
        cur.by += ny;
        if(maps[cur.bx][cur.by] == 'O') break;
    }

    // 겹침 처리만 하면 되는거 아닌가? 둘 다 O일 경우만 빼고.
    if(cur.rx == cur.bx && cur.ry == cur.by) {
        if(maps[cur.rx][cur.ry] == 'O') return cur;

        if(Bfirst) cur.ry++;
        else cur.by++;
    }

    return cur;
}

rblo right(rblo cur) {
    cur.time += 1;
    int ny = 1;
    bool Bfirst = false;
    while(maps[cur.rx][cur.ry+ny] != '#') {
        cur.ry += ny;
        if(maps[cur.rx][cur.ry] == 'O') break;
        if(cur.rx == cur.bx && cur.ry == cur.by) Bfirst = true;
    }
    while(maps[cur.bx][cur.by+ny] != '#') {
        cur.by += ny;
        if(maps[cur.bx][cur.by] == 'O') break;
    }

    // 겹침 처리만 하면 되는거 아닌가? 둘 다 O일 경우만 빼고.
    if(cur.rx == cur.bx && cur.ry == cur.by) {
        if(maps[cur.rx][cur.ry] == 'O') return cur;

        if(Bfirst) cur.ry--;
        else cur.by--;
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    queue<rblo> q;
    rblo first;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> maps[i][j];
            if(maps[i][j] == 'R') {
                first.rx = i;
                first.ry = j;
                maps[i][j] = '.';
            } else if(maps[i][j] == 'B') {
                first.bx = i;
                first.by = j;
                maps[i][j] = '.';
            }
        }
    }
    first.time = 0;
    q.push(first);
    visited[first.rx][first.ry][first.bx][first.by] = true;
    while(!q.empty()) {
        rblo cur = q.front();
        q.pop();
        if(cur.time==10) continue;
        rblo next;
        //up, R이 O일때 종료, 아니라면 visited 확인 후 push
        next = up(cur);
        if(maps[next.rx][next.ry] == 'O' || maps[next.bx][next.by] == 'O') {
            if(maps[next.rx][next.ry] == 'O' && maps[next.bx][next.by] != 'O') {
                cout << next.time << '\n';
                return 0;
            }
        } else if(!visited[next.rx][next.ry][next.bx][next.by]) {
            q.push(next);
            visited[next.rx][next.ry][next.bx][next.by] = true;
        }
        //down
        next = down(cur);
        if(maps[next.rx][next.ry] == 'O' || maps[next.bx][next.by] == 'O') {
            if(maps[next.rx][next.ry] == 'O' && maps[next.bx][next.by] != 'O') {
                cout << next.time << '\n';
                return 0;
            }
        } else if(!visited[next.rx][next.ry][next.bx][next.by]) {
            q.push(next);
            visited[next.rx][next.ry][next.bx][next.by] = true;
        }
        //left
        next = left(cur);
        if(maps[next.rx][next.ry] == 'O' || maps[next.bx][next.by] == 'O') {
            if(maps[next.rx][next.ry] == 'O' && maps[next.bx][next.by] != 'O') {
                cout << next.time << '\n';
                return 0;
            }
        } else if(!visited[next.rx][next.ry][next.bx][next.by]) {
            q.push(next);
            visited[next.rx][next.ry][next.bx][next.by] = true;
        }
        //right
        next = right(cur);
        if(maps[next.rx][next.ry] == 'O' || maps[next.bx][next.by] == 'O') {
            if(maps[next.rx][next.ry] == 'O' && maps[next.bx][next.by] != 'O') {
                cout << next.time << '\n';
                return 0;
            }
        } else if(!visited[next.rx][next.ry][next.bx][next.by]) {
            q.push(next);
            visited[next.rx][next.ry][next.bx][next.by] = true;
        }
    }

    cout << -1 << '\n';
}