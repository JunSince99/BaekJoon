#include <iostream>

using namespace std;

const int MAX = 1024 * 3 + 2;

int board[MAX][MAX*2-1];

void recur(const int s, const int x, const int y) {
    if (s==3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*', board[x+1][y+1] = '*';
        for(int i=y-2;i<=y+2;i++) {
            board[x+2][i] = '*';
        }
        return;
    }

    int ns = s / 2;
    recur(ns, x, y);
    recur(ns, x+ns, y-ns);
    recur(ns, x+ns, y+ns);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    recur(n,0,n-1);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n*2-1;j++) {
            if(board[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}