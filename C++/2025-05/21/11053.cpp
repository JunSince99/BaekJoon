#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N,1);
    vector<int> A(N);
    int lngth = 1;

    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if (A[j]<A[i]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        lngth = max(lngth, dp[i]);
    }

    cout << lngth << '\n';
    return 0;
}