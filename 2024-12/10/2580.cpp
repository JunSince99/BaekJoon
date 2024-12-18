#include <iostream>

using namespace std;

bool isvalid(int sudoku[9][9], int x, int y, int num) {
    for (int i=0;i<9;i++) {
        if (sudoku[x][i] == num || sudoku[i][y] == num) return false;
    }

    int dx = (x/3)*3;
    int dy = (y/3)*3;
    for (int i=dx;i<dx+3;i++) {
        for (int j=dy;j<dy+3;j++) {
            if (sudoku[i][j] == num) return false;
        }
    }

    return true;
}

bool solve(int sudoku[9][9]) {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (sudoku[i][j] == 0) {
                for (int ans=1;ans<=9;ans++) {
                    if (isvalid(sudoku,i,j,ans)) {
                        sudoku[i][j] = ans;
                        if (solve(sudoku)) return true;
                        else sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int sudoku[9][9];

    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cin >> sudoku[i][j];
        }
    }

    solve(sudoku);

    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (j==8) cout << sudoku[i][j] << endl;
            else cout << sudoku[i][j] << ' ';
        }
    }
}