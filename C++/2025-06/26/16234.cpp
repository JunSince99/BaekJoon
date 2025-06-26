#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int day;
int N, L, R;
int world[50][50];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L >> R;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        cin >> world[i][j];

    bool isdone = false;
    while(!isdone) {
        isdone = true;
        vector<vector<bool>> visited(N,vector<bool>(N,false));
        queue<pair<int,int>> q;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                vector<pair<int,int>> uni;
                int sum = 0;
                if(visited[i][j]) continue;

                q.push({i,j});
                visited[i][j] = true;
                uni.push_back({i,j});
                sum += world[i][j];

                while(!q.empty()) {
                    auto [x,y] = q.front(); q.pop();

                    for(int d=0;d<4;d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx<0 || nx>=N || ny<0 || ny>=N || visited[nx][ny]) continue;
                        int different = abs(world[x][y]-world[nx][ny]);
                        if(different>=L && different<=R) {
                            q.push({nx,ny});
                            visited[nx][ny] = true;
                            uni.push_back({nx,ny});
                            sum += world[nx][ny];
                            isdone = false;
                        }
                    }
                }
                sum = sum / uni.size();
                for(auto& re : uni) {
                    world[re.first][re.second] = sum;
                }
            }
        }
        if(isdone) {
            cout << day << '\n';
            return 0;
        }
        day++;
    }
}