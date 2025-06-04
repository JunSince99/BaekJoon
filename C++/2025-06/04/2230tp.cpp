#include <iostream>
#include <algorithm>
using namespace std;

int ans = 2e9+1;
int N,M;
int nums[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> nums[i];

    sort(nums,nums+N);
    int left = 0;
    int right = 0;
    while(left<N) {
        while(right < N && nums[right] - nums[left] < M) right++;
        if(right == N) break;
        ans = min(ans, nums[right] - nums[left]);
        left++;
    }
    cout << ans;
}