#include <iostream>
using namespace std;

int board[9][9];

bool ispos(int x, int y, int num) {
    //가로 세로
    for(int i=0;i<9;i++) {
        if(board[i][y] == num) return false;
        if(board[x][i] == num) return false;
    }

    int nx = (x/3)*3, ny = (y/3)*3;
    for(int i=nx;i<nx+3;i++) {
        for(int j=ny;j<ny+3;j++) {
            if(board[i][j]==num) return false;
        }
    }
    return true;
}

bool dfs() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            if(board[i][j] == 0) {
                for(int k=1;k<10;k++) {
                    if(ispos(i,j,k)) {
                        board[i][j] = k;
                        if(dfs()) return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<9;i++) {
        string s;
        cin >> s;
        for(int j=0;j<9;j++) {
            board[i][j] = s[j] - '0';
        }
    }

    dfs();

    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}