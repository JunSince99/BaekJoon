#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> pyra(n,vector<int>(n));
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cin >> pyra[i][j];
        }
    }
    
    for(int i=0;i<n;i++) {
        dp[n-1][i] = pyra[n-1][i];
    }

    for(int i=n-2;0<=i;i--) {
        for(int j=0;j<=i;j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + pyra[i][j];
        }
    }
    
    cout << dp[0][0] << '\n';
    return 0;
}