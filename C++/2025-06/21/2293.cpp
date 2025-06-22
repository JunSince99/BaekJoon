#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<int> coin(n);
    for(int i=0;i<n;i++) cin >> coin[i];

    vector<int> dp(k+1, 0);
    dp[0] = 1;

    for(int i=0;i<n;i++)
    for(int j=coin[i];j<=k;j++)
        dp[j] += dp[j-coin[i]];

    cout << dp[k] << '\n';
}