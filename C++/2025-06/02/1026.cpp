#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[50];
int B[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
        cin >> B[i];

    sort(A,A+N);
    sort(B,B+N,greater<>());

    int ans = 0;
    for(int i=0;i<N;i++)
        ans += A[i] * B[i];
    cout << ans;
}