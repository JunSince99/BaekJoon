#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<vector<int>> houses(N,vector<int>(3));
    vector<vector<int>> dp(N,vector<int>(3));
    
    for(int i=0;i<N;i++) {
        cin >> houses[i][0] >> houses[i][1] >> houses[i][2];
    }

    dp[0][0] = houses[0][0];
    dp[0][1] = houses[0][1];
    dp[0][2] = houses[0][2];

    for(int i=1;i<N;i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + houses[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + houses[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + houses[i][2];
    }

    int maxdp = min(dp[N-1][0], dp[N-1][1]);
    maxdp = min(maxdp,dp[N-1][2]);
    cout << maxdp << '\n';

    return 0;
}