#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans = 0;
int board[500][500];
bool visited[500][500];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int i, int j, int depth, int sum) {
    if(depth == 4) {
        ans = max(ans, sum);
        return;
    }
    for(int k=0;k<4;k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(0<=nx && nx<N && 0<=ny && ny<M && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx,ny,depth+1,sum+board[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

void linedot(int i, int j) {
    // ㅗ
    if(0<i && i<N && 0<j && j<M-1) {
        ans = max(ans, board[i][j] + board[i][j-1] + board[i-1][j] + board[i][j+1]);
    }
    // ㅏ
    if(0<i && i<N-1 && 0<=j && j<M-1) {
        ans = max(ans, board[i][j] + board[i-1][j] + board[i][j+1] + board[i+1][j]);
    }
    // ㅜ
    if(0<=i && i<N-1 && 0<j && j<M-1) {
        ans = max(ans, board[i][j] + board[i][j+1] + board[i+1][j] + board[i][j-1]);
    }
    // ㅓ
    if(0<i && i<N-1 && 0<j && j<M) {
        ans = max(ans, board[i][j] + board[i+1][j] + board[i][j-1] + board[i-1][j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visited[i][j] = true;
            dfs(i,j,1,board[i][j]);
            visited[i][j] = false;
            linedot(i,j);
        }
    }

    cout << ans << '\n';
    return 0;
}