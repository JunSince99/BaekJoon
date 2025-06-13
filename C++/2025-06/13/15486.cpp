#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> sche(N);
    vector<int> dp(N+1,0);
    for(int i=0;i<N;i++) cin >> sche[i].first >> sche[i].second;
    dp[N] = 0;

    for(int i=N-1;i>=0;--i) {
        if(i+sche[i].first <= N) {
            dp[i] = max(dp[i+sche[i].first] + sche[i].second, dp[i+1]);
        } else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[0];
}