#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> dp(N+1,vector<int>());
    dp[1].push_back(1);
    for(int i=2;i<=N;i++) {
        int mostidx;
        int mostval = 1e9;
        if(i%2==0) {
            if(mostval > dp[i/2].size()-1) {
                mostval = dp[i/2].size()-1;
                mostidx = i/2;
            }
        }
        if(i%3==0) {
            if(mostval > dp[i/3].size()-1) {
                mostval = dp[i/3].size()-1;
                mostidx = i/3;
            }
        }
        if(mostval > dp[i-1].size()-1) {
            mostval = dp[i-1].size()-1;
            mostidx = i-1;
        }
        dp[i] = dp[mostidx];
        dp[i].push_back(i);
    }

    cout << dp[N].size()-1 << '\n';
    for(int i=dp[N].size()-1;i>=0;i--) {
        cout << dp[N][i] << ' ';
    }
    cout << '\n';
}