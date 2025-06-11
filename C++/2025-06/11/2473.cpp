#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long most = 3000000001;
long long answer[3];
long long liq[5001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) cin >> liq[i];
    sort(liq,liq+N);

    for(int i=0;i<N-2;i++) {
        int left = i+1, right = N-1;
        
        while(left<right) {
            long long sum = liq[i] + liq[left] + liq[right];

            if (llabs(sum) < llabs(most)) {
                answer[0] = liq[i];
                answer[1] = liq[left];
                answer[2] = liq[right];
                most = sum;
            }

            if(sum < 0) left++;
            else right--;
        }
    }
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2];
}