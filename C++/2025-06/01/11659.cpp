#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    vector<int> nums(N);
    vector<int> dp(N);
    for(int i=0;i<N;i++) cin >> nums[i];
    dp[0] = nums[0];
    for(int i=1;i<N;i++) {
        dp[i] = dp[i-1] + nums[i];
    }

    for(int t=0;t<M;t++) {
        int i,j;
        cin >> i >> j;
        if(i == 1) cout << dp[j-1] << '\n';
        else cout << dp[j-1] - dp[i-2] << '\n';
    }
}