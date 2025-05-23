#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2,vector<int>(n));
        vector<vector<int>> dp(2,vector<int>(n));
        for(int i=0;i<2;i++) {
            for(int j=0;j<n;j++) {
                cin >> sticker[i][j];
            }
        }
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[0][1] + dp[1][0];
        dp[1][1] = sticker[1][1] + dp[0][0];

        for(int i=2;i<n;i++) {
            dp[0][i] = max(dp[1][i-2], dp[1][i-1]) + sticker[0][i];
            dp[1][i] = max(dp[0][i-2], dp[0][i-1]) + sticker[1][i];
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }

    return 0;
}