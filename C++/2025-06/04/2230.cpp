#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int ans = 2e9+1;
int nums[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> nums[i];

    sort(nums,nums+N);
    for(int i=0;i<N;i++) {
        int idx = lower_bound(nums, nums+N, nums[i] + M) - nums;
        if(idx<N) {
            ans = min(ans, nums[idx] - nums[i]);
        }
    }

    cout << ans;
}