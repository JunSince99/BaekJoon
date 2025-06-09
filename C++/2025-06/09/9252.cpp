#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string fir, sec;
    cin >> fir >> sec;

    for(int i=1;i<=fir.size();i++) {
        for(int j=1;j<=sec.size();j++) {
            if(fir[i-1] == sec[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    cout << dp[fir.size()][sec.size()] << '\n';

    string lcs;
    int i = fir.size();
    int j = sec.size();
    while(i>0 && j>0) {
        if(fir[i-1] == sec[j-1]) {
            lcs += fir[i-1];
            i--;
            j--;
        } else if(dp[i][j-1] > dp[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }

    reverse(lcs.begin(),lcs.end());
    if(!lcs.empty())
        cout << lcs << '\n';
}