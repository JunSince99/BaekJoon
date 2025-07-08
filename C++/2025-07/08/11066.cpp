#include <iostream>
using namespace std;

int T;
int K;
int file[501];
int dp[501][501];
int presum[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> K;
        for(int i=1;i<=K;i++) {
            cin >> file[i];
            presum[i] = presum[i-1] + file[i];
        }

        for(int len=2;len<=K;len++) {
            for(int i=1;i<=K-len+1;i++) {
                int j = i+len-1;
                dp[i][j] = 1e9;
                int Sum = presum[j] - presum[i-1];
                for(int k=i;k<j;k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + Sum);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }
}