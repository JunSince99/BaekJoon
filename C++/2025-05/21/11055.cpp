#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N);

    for(int i=0;i<N;i++) {
        cin >> A[i];
        dp[i] = A[i];
    }
    int mdp = A[0];

    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(A[j]<A[i]) {
                dp[i] = max(dp[i],dp[j]+A[i]);
            }
        }
        mdp = max(mdp, dp[i]);
    }

    cout << mdp << '\n';
    return 0;
}