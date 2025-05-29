#include <iostream>
using namespace std;

int N;
int board[15] = {-1};
int cnt;

bool iscan(int x, int y) {
    //세로 확인
    //대각선 확인
    for(int i=0;i<x;i++) {
        if(board[0] != -1) {
            if(y==board[i]) return false;
            if(x-i == y-board[i]) return false;
            if(x-i == board[i]-y) return false;
        }
    }
    return true;
}

void backtrack(int depth) {
    if (depth == N) {
        cnt++;
        return;
    }
    for(int i=0;i<N;i++) {
        if(iscan(depth, i)) {
            board[depth] = i;
            backtrack(depth+1);
            board[depth] = -1;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    backtrack(0);

    cout << cnt << '\n';
}