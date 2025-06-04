#include <iostream>
#include <algorithm>
using namespace std;

int ans = 1e9;
int N,S;
int nums[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> nums[i];
    
    int left = 0;
    int right = 0;
    int cur = 0;
    while(left<N) {
        while(right<N && cur < S) {
            cur += nums[right++];
        }
        if(cur < S) break;
        ans = min(ans, right-left);
        cur -= nums[left++];
    }

    if(ans == 1e9) cout << 0 << '\n';
    else cout << ans << '\n';
}