#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int M,N;
int maze[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dijk() {
    vector<vector<int>> d(N,vector<int>(M,INF));
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    d[0][0] = 0;
    pq.push({0,0,0}); // cost, x, y
    while(!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();

        if(d[x][y] != cost) continue;

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M) {
                if(cost + maze[nx][ny] < d[nx][ny]) {
                    d[nx][ny] = cost + maze[nx][ny];
                    pq.push({d[nx][ny], nx,ny});
                }
            }
        }
    }

    return d[N-1][M-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<M;j++) {
            maze[i][j] = temp[j] - '0';
        }
    }

    cout << dijk();

}