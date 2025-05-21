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
    vector<int> dp(N,1);
    int mdp = 1;

    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    for(int i=N-2;0<=i;i--) {
        for(int j=N-1;i<j;j--) {
            if(A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mdp = max(mdp, dp[i]);
    }

    cout << mdp << '\n';
    return 0;
}