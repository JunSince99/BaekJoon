#include <iostream>
#include <algorithm>
using namespace std;

int n;
int T[15];
int P[15];
int dp[16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) cin >> T[i] >> P[i];
    dp[n] = 0;

    for(int i=n-1;i>=0;i--) {
        if(i+T[i]<=n) {
            dp[i] = max(P[i]+dp[i+T[i]], dp[i+1]);
        } else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[0];
}