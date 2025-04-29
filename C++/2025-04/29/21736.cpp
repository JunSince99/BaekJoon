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

    vector<vector<char>> map(N,vector<char> (M));
    vector<vector<bool>> visited(N,vector<bool> (M,false));
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
            if(map[i][j] == 'I') {
                q.push({i,j});
                visited[i][j] = true;
            } else if(map[i][j] == 'X') {
                visited[i][j] = true;
            }
        }
    }

    int friends = 0;
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(0<= nx && nx < N && 0<=ny && ny<M && !visited[nx][ny]) {
                if(map[nx][ny] == 'P')
                    friends++;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    if (friends == 0) {
        cout << "TT" << '\n';
    } else {
        cout << friends << '\n';
    }

    return 0;
}