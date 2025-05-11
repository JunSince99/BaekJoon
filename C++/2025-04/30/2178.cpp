#include <iostream>
#include <vector>
#include <queue>

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<vector<int>> maps(N, vector<int> (M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for(int i=0;i<N;i++) {
        string row;
        cin >> row;
        for(int j=0;j<M;j++) {
            maps[i][j] = row[j] - '0';
            if(maps[i][j] == 0) {
                visited[i][j] = true;
            }
        }
    }

    queue<vector<int>> q;
    q.push({0,0,1});
    visited[0][0] = true;

    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        if(cur[0] == N-1 && cur[1] == M-1) {
            cout << cur[2] << '\n';
            return 0;
        }

        for(int i=0;i<4;i++) {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<M && !visited[nx][ny]) {
                q.push({nx,ny,cur[2]+1});
                visited[nx][ny] = true;
            }
        }
    }

    return 0;
}