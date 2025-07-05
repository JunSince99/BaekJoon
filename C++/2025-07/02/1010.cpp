#include <iostream>
using namespace std;

int dp[30][30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for(int i=2;i<30;i++) dp[1][i] = i;
    for(int i=1;i<30;i++) dp[i][i] = 1;

    for(int i=2;i<30;i++) {
        for(int j=2;j<30;j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        }
    }

    while(T--) {
        int a,b;
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}