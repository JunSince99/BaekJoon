#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C,N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> N;
    vector<pair<int, int>> city(N);
    vector<int> dp(C+101,2e9);
    dp[0] = 0;
    for(int i=0;i<N;i++) cin >> city[i].first >> city[i].second;

    for(int i=0;i<=C;i++) {
        for(int j=0;j<N;j++) {
            if(dp[i+city[j].second] > dp[i] + city[j].first) {
                dp[i+city[j].second] = dp[i] + city[j].first;
            }
        }
    }

    int ans = 2e9;
    for(int i=C;i<=C+100;i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans << '\n';
}