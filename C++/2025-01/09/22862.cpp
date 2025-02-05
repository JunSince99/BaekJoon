#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin >> N >> K;

    vector<int> S(N);
    for(int i=0;i<N;i++) {
        cin >> S[i];
    }

    int left=0,right=0;
    int oddcnt = 0;
    int maxlength = 0;
    while(right<N) {
        if (S[right] % 2 != 0) { // right가 홀수면
            oddcnt++;
        }

        while(oddcnt > K) {
            if (S[left] % 2 != 0) {
                oddcnt--;
            }
            left++;
        }
        maxlength = max(maxlength, right-left+1-oddcnt);

        right++;
    }
    cout << maxlength << '\n';

    return 0;
}