#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[10000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    sort(A,A+N);

    long long cnt = 0;
    for(int i=0;i<N-2;i++)
        for(int j=i+1;j<N-1;j++)
            cnt += upper_bound(A + j + 1, A + N, -(A[i] + A[j])) - lower_bound(A + j + 1, A + N, -(A[i] + A[j]));
    cout << cnt;
}