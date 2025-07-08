#include <iostream>
#include <vector>
using namespace std;

int Maxeated;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

void gogoShark(int x, int y, int cureat, vector<vector<pair<int,int>>> curmap, vector<pair<int,int>> curfish) {
    // 물고기 이동
    for(int i=1;i<=16;i++) {
        auto [fx, fy] = curfish[i];
        if (fx == -1) continue;
        int cur = curmap[fx][fy].first;
        int dir = curmap[fx][fy].second; 
        for(int d=0;d<8;d++) {
            int nfx = fx + dx[dir];
            int nfy = fy + dy[dir];

            if(nfx>=0 && nfx<4 && nfy>=0 && nfy<4 && curmap[nfx][nfy].first != -1) {
                int targetfish = curmap[nfx][nfy].first;
                int tfdir = curmap[nfx][nfy].second;

                curfish[targetfish] = {fx,fy};
                curfish[cur] = {nfx, nfy};

                curmap[nfx][nfy] = {cur,dir};
                curmap[fx][fy] = {targetfish, tfdir};

                break;
            }
            //반시계
            dir = (dir+9)%8;
        }
    }
    // 상어 이동 가능한 곳 전부 gogoShark
        // 이동할 곳 없으면 Maxeated 갱신후 return;
    bool canmove = false;
    for(int i=1;i<4;i++) {
        int dir = curmap[x][y].second;
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;

        if(nx<0 || nx>=4 || ny<0 || ny>=4 || curmap[nx][ny].first < 1) continue;
        canmove = true;
        vector<vector<pair<int,int>>> nxtmap;
        vector<pair<int,int>> nxtfish;

        nxtmap = curmap;
        nxtfish = curfish;

        int willeat = nxtmap[nx][ny].first;
        nxtmap[nx][ny].first = -1;
        nxtmap[x][y] = {0,0};
        nxtfish[willeat] = {-1,-1};
        gogoShark(nx,ny,cureat+willeat, nxtmap, nxtfish);
    }

    if(!canmove) {
        Maxeated = max(Maxeated, cureat);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<pair<int,int>>> map(4,vector<pair<int,int>>(4));
    vector<pair<int,int>> fishes(17);

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            int a,b;
            cin >> a >> b;
            map[i][j] = {a,b-1};
            fishes[a] = {i,j};
        }
    }

    Maxeated += map[0][0].first;
    fishes[map[0][0].first] = {-1,-1};
    map[0][0] = {-1, map[0][0].second};
    gogoShark(0,0,Maxeated,map,fishes);

    cout << Maxeated;
}

// 맵은 무조건 4x4 고정
// 1. 0,0에 있는 물고기 먹고 해당 물고기 방향 가지기
// 물고기 번호 순서대로 이동
    // 빈칸이나 다른 물고기가 있는 칸과 Swap 해주기
    // 이동 못하면 반시계방향으로 회전
// 이동 다 하면 상어 이동 = 해당 방향에 있는 물고기 모두 먹을 수 있음
// 물고기 아예 없으면 끝
// dfs로 모든 경우의 수 확인 후 먹은 물고기 번호의 합 최댓값 출력