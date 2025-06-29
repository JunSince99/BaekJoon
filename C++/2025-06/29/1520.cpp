#include <iostream>
using namespace std;

int cnt;
int n,m;
int map[500][500];
bool visited[500][500];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x, int y) {
    if(x == n-1 && y == m-1) {
        cnt++;
        return;
    }

    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
        if(map[x][y]>map[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx,ny);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
        }
    }
    dfs(0,0);
    cout << cnt;
}