#include <iostream>
using namespace std;

int R,C;

string board[10000];
bool visited[10000][500];

int dx[3] = {-1,0,1};

bool dfs(int r, int c) {
    if (c == C-1) return true;

    for(int i=0;i<3;i++) {
        int nx = r + dx[i];
        int ny = c+1;

        if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
        if(board[nx][ny] == 'x' || visited[nx][ny]) continue;

        visited[nx][ny] = true;
        if(dfs(nx,ny)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for(int i=0;i<R;i++) cin >> board[i];

    int answer = 0;

    for(int i=0;i<R;i++) {
        visited[i][0] = true;

        if (dfs(i,0)) answer++;
    }

    cout << answer;
}