#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int n;
int map[500][500];
int dp[500][500];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dfs(int x, int y) {
    if(dp[x][y]) return dp[x][y];

    dp[x][y] = 1;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(map[x][y] < map[nx][ny])
            dp[x][y] = max(dp[x][y], dfs(nx,ny) + 1);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin >> map[i][j];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans = max(ans, dfs(i,j));
        }
    }
    cout << ans;
}