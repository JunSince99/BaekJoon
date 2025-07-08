#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int catchCnt;
int R,C,M;
int maps[101][101];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

struct shark{
    int x,y;
    int speed;
    int dir; // 0 1 2 3 위 아래 오른쪽 왼쪽
    int size;
};

shark SS[10000];

int revert(int d) {
    if(d==0) return 1;
    else if(d==1) return 0;
    else if(d==2) return 3;
    else if(d==3) return 2;

    return -1;
}

void letsMoveSharkYeeeah() {
    queue<int> q;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if (maps[i][j] != -1) {
                q.push(maps[i][j]);
                maps[i][j] = -1;
            }
        }
    }

    //큐 하나씩 확인하면서 상어 이동시키기. 이미 상어가 있으면 크기 비교후 하나 컷
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        int nxtX = SS[cur].x + dx[SS[cur].dir] * SS[cur].speed;
        int nxtY = SS[cur].y + dy[SS[cur].dir] * SS[cur].speed;

        while(nxtX<1 || nxtX>R) {
            if (nxtX<1) {
                nxtX = 2 - nxtX;
                SS[cur].dir = revert(SS[cur].dir);
            } else if(nxtX>R) {
                nxtX = 2 * R - nxtX;
                SS[cur].dir = revert(SS[cur].dir);
            }
        }

        while(nxtY<1 || nxtY>C) {
            if (nxtY<1) {
                nxtY = 2 - nxtY;
                SS[cur].dir = revert(SS[cur].dir);
            } else if(nxtY>C) {
                nxtY = 2 * C - nxtY;
                SS[cur].dir = revert(SS[cur].dir);
            }
        }

        if(maps[nxtX][nxtY] == -1) {
            maps[nxtX][nxtY] = cur;
            SS[cur].x = nxtX;
            SS[cur].y = nxtY;
        } else {
            int compare = maps[nxtX][nxtY];
            if(SS[cur].size>SS[compare].size) { //cur이 더 커
                maps[nxtX][nxtY] = cur;
                SS[cur].x = nxtX;
                SS[cur].y = nxtY;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;
    
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            maps[i][j] = -1;

    for(int i=0;i<M;i++) {
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        SS[i] = {r,c,s,d-1,z};
        maps[r][c] = i;
    }

    for(int j=1;j<=C;j++) {
        // 이 열을 하나씩 돌면서 상어를 찾고 상어 찾으면 catchCnt++, 해당 상어 없애기
        for(int i=1;i<=R;i++) {
            if(maps[i][j] != -1) {
                catchCnt += SS[maps[i][j]].size;
                maps[i][j] = -1;
                break;
            }
        }

        // 상어 이동
        letsMoveSharkYeeeah();
    }

    cout << catchCnt << '\n';
}