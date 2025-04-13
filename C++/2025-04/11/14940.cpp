#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> maps(n,vector<int> (m));
    vector<vector<int>> distance(n,vector<int> (m, -1));
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    int startX,startY;
    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            cin >> maps[i][j];

            if(maps[i][j] == 2) {
                startX = i;
                startY = j;
            } else if(maps[i][j] == 0) {
                distance[i][j] = 0;
            }
        }
    }

    queue<array<int, 3>> q;
    q.push({startX,startY,0});
    visited[startX][startY] = true;
    while(!q.empty()) {
        array<int,3> cur = q.front();
        q.pop();

        distance[cur[0]][cur[1]] = cur[2];

        for(int i=0;i<4;i++) {
            int mx = cur[0] + dx[i];
            int my = cur[1] + dy[i];

            if (0<=mx && mx<n && 0<=my && my<m && !visited[mx][my] && maps[mx][my] == 1) {
                q.push({mx,my,cur[2]+1});
                visited[mx][my] = true;
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}