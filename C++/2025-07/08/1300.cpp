#include <iostream>
using namespace std;

typedef long long ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    ll left = 1;
    ll right = n*n;
    ll answer = 0;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        for (int i=1;i<=n;i++)
            cnt += min(mid / i, n);
        if(cnt >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
}   