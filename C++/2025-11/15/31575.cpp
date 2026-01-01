#include <iostream>
#include <queue>

using namespace std;

bool visited[301][301];

int dx[4] = {1,0};
int dy[4] = {0,1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    int maps[301][301];
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            cin >> maps[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == M-1 && y == N-1) {
            cout << "Yes";
            return 0;
        }

        for(int i=0;i<2;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx>=M || ny<0 || ny>=N || maps[nx][ny] == 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }

    cout << "No";
}