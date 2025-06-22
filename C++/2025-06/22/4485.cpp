#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int T = 1;
int N;
int cave[125][125];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct abc{
    int w;
    int a;
    int b;
    bool operator>(const abc& other) const {
        return w > other.w;
    }
};

int dijk(int x, int y) {
    vector<vector<int>> d(N,vector<int>(N,INF));
    d[x][y] = cave[x][y];

    priority_queue<abc,vector<abc>,greater<abc>> pq;
    pq.push({d[x][y],x,y});
    while(!pq.empty()) {
        int curx = pq.top().a;
        int cury = pq.top().b;
        int curw = pq.top().w;
        pq.pop();

        if(d[curx][cury] != curw) continue;

        for(int i=0;i<4;i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<N) {
                if(curw+cave[nx][ny]<d[nx][ny]) {
                    d[nx][ny] = curw+cave[nx][ny];
                    pq.push({d[nx][ny],nx,ny});
                }
            }
        }
    }

    return d[N-1][N-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> N;
        if(N==0) return 0;
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        cin >> cave[i][j];
        cout << "Problem " << T++ << ": " << dijk(0,0) << '\n';
    }
}