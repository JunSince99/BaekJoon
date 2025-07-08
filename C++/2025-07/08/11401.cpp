#include <iostream>
using namespace std;

typedef long long ll;
const ll P = 1000000007;
int n,k;
ll facto[4000001];

ll powerPow(ll a, ll b) {
    ll result = 1;
    while(b>0) {
        if (b % 2 == 1) result = (result * a) % P;
        a = (a * a) % P;
        b /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    //n! 까지 모든 팩토리얼 미리 구하기 O(n)
    facto[0] = 1;
    for(int i=1;i<=n;i++) {
        facto[i] = (facto[i-1] * i) % P;
    }

    //n!, k!*(n-k)!의 1000000005승 곱하고 나머지
    ll A = facto[n];
    ll B = (facto[k] * facto[n-k]) % P;
    B = powerPow(B, P-2);

    ll answer = (A * B) % P;
    cout << answer << '\n';
}