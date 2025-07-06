#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
int n,k;
int coins[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<int> dp(k+1, INF);
    dp[0] = 0;
    for(int i=0;i<n;i++) cin >> coins[i];

    for(int i=1;i<=k;i++)
        for(int& c : coins)
            if(i - c >=0 && dp[i-c] != INF)
                dp[i] = min(dp[i], dp[i-c] + 1);
    
    if(dp[k] == INF) cout << -1;
    else cout << dp[k];
}