#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<vector<int>> dp(N,vector<int>());
    vector<int> mdp;

    for(int i=0;i<N;i++) {
        cin >> A[i];
        dp[i].push_back(A[i]);
    }
    mdp = dp[0];

    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if (A[j] < A[i]) {
                if (dp[i].size() < dp[j].size()+1) {
                    dp[i] = dp[j];
                    dp[i].push_back(A[i]);
                }
            }
        }
        if (mdp.size() < dp[i].size()) {
            mdp = dp[i];
        }
    }
    cout << mdp.size() << '\n';
    for(int i : mdp) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}