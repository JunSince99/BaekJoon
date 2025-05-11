#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> maps(N, vector<int>(N));
    vector<vector<bool>> visited(N,vector<bool>(N, false));
    for(int i=0;i<N;i++) {
        string row;
        cin >> row;
        for(int j=0;j<N;j++) {
            maps[i][j] = row[j] - '0';
            if(maps[i][j] == 0) {
                visited[i][j] = true;
            }
        }
    }

    vector<int> numbers;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                queue<vector<int>> q;
                int cnt = 0;
                q.push({i,j});
                visited[i][j] = true;
                cnt++;
                while(!q.empty()) {
                    vector<int> cur = q.front();
                    q.pop();

                    for(int k=0;k<4;k++) {
                        int nx = cur[0] + dx[k];
                        int ny = cur[1] + dy[k];

                        if(0<=nx && nx<N && 0<=ny && ny<N && !visited[nx][ny]) {
                            q.push({nx,ny});
                            visited[nx][ny] = true;
                            cnt++;
                        }
                    }
                }
                numbers.push_back(cnt);
            }
        }
    }

    sort(numbers.begin(), numbers.end());
    cout << numbers.size() << '\n';
    for(int n:numbers) {
        cout << n << '\n';
    }

    return 0;
}