#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool mask[25] = {false};
string board[5];
int ans;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<5;i++)
        cin >> board[i];

    fill(mask+18,mask+25,true);
    do{
        //mask값에 의거, bool seven[][]에 공주 위치 표시
        //bfs로 한덩어리인지, S갯수 세기
        bool seven[5][5] = {false}, visited[5][5] = {false};
        int cnt = 0, S = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<25;i++) {
            if(mask[i]) {
                int x = i/5, y = i%5;
                seven[x][y] = true;
                if(q.empty()) {
                    q.push({x,y});
                    visited[x][y] = true;
                    cnt++;
                    if(board[x][y] == 'S') S++;
                }
            }
        }

        while(!q.empty()) {
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if(0<=nx && nx<5 && 0<=ny && ny<5 && seven[nx][ny] && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    cnt++;
                    if(board[nx][ny] == 'S') S++;
                }
            }
        }

        if (cnt >= 7 && S>=4) ans++;
    } while(next_permutation(mask,mask+25));
    cout << ans << '\n';
}