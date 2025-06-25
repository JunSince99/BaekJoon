#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
pair<int,int> baby;
int babybig = 2;
int babycnt = 0;
int babytime = 0;
int maps[20][20];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(int x, int y) { //baby에서 x,y 까지의 거리.
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<tuple<int,int,int>> q;
    q.push({baby.first, baby.second, 0});
    visited[baby.first][baby.second] = true;
    while(!q.empty()) {
        auto [curx, cury, time] = q.front(); q.pop();

        if(curx == x && cury == y) return time;

        for(int i=0;i<4;i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(0<=nx && nx<n && 0<=ny && ny<n && !visited[nx][ny] && maps[nx][ny]<=babybig) {
                visited[nx][ny] = true;
                q.push({nx,ny,time+1});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> maps[i][j];
            if(maps[i][j] == 9) {
                baby = {i,j};
                maps[i][j] = 0;
            }
        }
    }
    // 순회하며 먹을 수 있는 물고기일 경우 bfs로 거리를 측정한다. (babybig보다 작은것)
    // 거리와 함께 좌표를 push한다.
    while(true) {
        vector<tuple<int,int,int>> pq;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(maps[i][j] != 0 && maps[i][j]<babybig) {
                    int cost = bfs(i,j);
                    if(cost > 0) {
                        pq.push_back({cost,i,j});
                    }
                }
            }
        }

        if(pq.empty()) {
            cout << babytime << '\n';
            return 0;
        }

        sort(pq.begin(),pq.end());
        auto [curcost, x, y] = pq[0];

        babytime += curcost; // 이동 시간 추가
        baby = {x,y}; // 아기상어 이동
        maps[x][y] = 0; // 물고기 먹히기
        babycnt++;// 먹은 물고기 수
        if(babycnt == babybig) {
            babybig++;
            babycnt = 0;
        }
    }
}