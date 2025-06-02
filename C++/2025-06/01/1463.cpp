#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N+1, 1e9);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=N;i++) {
        int two = 1e9;
        int three = 1e9;
        int minus = 1e9;
        if(i%2==0) two = dp[i/2] + 1;
        if(i%3==0) three = dp[i/3] + 1;
        minus = dp[i-1] + 1;
        dp[i] = min(two, three);
        dp[i] = min(dp[i], minus);
    }
    cout << dp[N];
}