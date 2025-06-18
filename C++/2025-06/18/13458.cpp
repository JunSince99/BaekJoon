#include <iostream>
using namespace std;

int n,b,c;
int A[1000000];
long long ans=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    cin >> b >> c;

    for(int i=0;i<n;i++) {
        int cnt = 0;
        int stu = A[i];

        stu -= b;
        ans++;
        if(stu<=0) continue;
        cnt += stu / c;
        if(stu % c > 0) cnt++;
        ans += cnt;
    }

    cout << ans;
}