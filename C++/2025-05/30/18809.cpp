#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ans;
int garden[50][50];
vector<pair<int,int>> canspread;
int N, M;
int G, R;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct bae {
    int x;
    int y;
    int color;
    int day;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> garden[i][j];
            if(garden[i][j] == 2)
                canspread.push_back({i,j});
        }
    }
    vector<int> pick; //G가 0 R이 1
    for(int i=0;i<canspread.size()-G-R;i++)
        pick.push_back(0);
    for(int i=0;i<G;i++)
        pick.push_back(1);
    for(int i=0;i<R;i++)
        pick.push_back(2);

    do {
        vector<vector<pair<int,int>>> visited(N,vector<pair<int,int>>(M,pair<int,int>(-1,0)));
        queue<bae> q;
        int cnt=0;
        for(int i=0;i<pick.size();i++) {
            int curx = canspread[i].first;
            int cury = canspread[i].second;
            if(pick[i] == 1) {
                q.push({curx,cury,1,0});
                visited[curx][cury] = {0,1}; //도달시간, 색깔
            } else if(pick[i] == 2) {
                q.push({curx,cury,2,0});
                visited[curx][cury] = {0,2}; //도달시간, 색깔
            }
        }
        while(!q.empty()) {
            bae cur = q.front();
            q.pop();

            if(visited[cur.x][cur.y].second == 3) continue;

            for(int i=0;i<4;i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<M && garden[nx][ny] != 0 && visited[nx][ny].second != 3) {
                    if(visited[nx][ny].first == -1) {
                        q.push({nx,ny,cur.color,cur.day+1});
                        visited[nx][ny] = {cur.day+1,cur.color};
                    } else if(visited[nx][ny].second != cur.color && visited[nx][ny].first == cur.day+1) {
                        cnt++;
                        visited[nx][ny] = {cur.day+1, 3};
                    }
                }
            }
        }
        ans = max(ans, cnt);
    } while (next_permutation(pick.begin(),pick.end()));

    cout << ans;
}