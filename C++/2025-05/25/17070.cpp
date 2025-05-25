#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> maps(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> maps[i][j];
        }
    }

    int answer = 0;
    queue<tuple<int,int,int>> q;
    q.push({0,1,0});
    while(!q.empty()) {
        int curx, cury, dir;
        tie(curx, cury, dir) = q.front();
        q.pop();

        if(curx == n-1 && cury == n-1) {
            answer++;
            continue;
        }

        if(dir == 0) {
            int dx = curx;
            int dy = cury + 1;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1) {
                q.push({dx,dy,0});
            }
            dx++;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1 && maps[dx-1][dy] != 1 && maps[dx][dy-1] != 1) {
                q.push({dx,dy,2});
            }
        } else if(dir == 1) {
            int dx = curx + 1;
            int dy = cury;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1) {
                q.push({dx,dy,1});
            }
            dy++;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1 && maps[dx-1][dy] != 1 && maps[dx][dy-1] != 1) {
                q.push({dx,dy,2});
            }
        } else if(dir == 2) {
            int dx = curx + 1;
            int dy = cury;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1) {
                q.push({dx,dy,1});
            }
            dy++;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1 && maps[dx-1][dy] != 1 && maps[dx][dy-1] != 1) {
                q.push({dx,dy,2});
            }
            dx--;
            if(0<=dx && dx<n && 0<=dy && dy<n && maps[dx][dy] != 1) {
                q.push({dx,dy,0});
            }
        }
    }

    cout << answer << '\n';
    return 0;
}