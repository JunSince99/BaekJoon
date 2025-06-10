#include <iostream>
using namespace std;

int N;
int ans = 2e9;
int town[1001][3];
int dp[1001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> town[i][0] >> town[i][1] >> town[i][2];
    for(int one=0;one<3;one++) {
        dp[0][0] = town[0][one];
        dp[0][1] = town[0][one];
        dp[0][2] = town[0][one];
        for(int i=1;i<N;i++) {
            if(i==1) {
                dp[i][0] = dp[0][0] + town[i][0];
                dp[i][1] = dp[0][0] + town[i][1];
                dp[i][2] = dp[0][0] + town[i][2];
                dp[i][one] = 2e9;
                continue;
            }
            if(i==N-1) {
                dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + town[i][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + town[i][1];
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + town[i][2];
                dp[i][one] = 2e9;
                continue;
            }
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + town[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + town[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + town[i][2];
        }
        int temp = min(dp[N-1][0], dp[N-1][1]);
        temp = min(temp, dp[N-1][2]);
        ans = min(ans, temp);
    }

    cout << ans;
}