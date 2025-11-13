#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long t[10000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long answer = 0;

    cin >> N;
    for(int i=0;i<N;i++) cin >> t[i];

    sort(t,t+N);
    if(N % 2 == 0) {
        int l = 0;
        int r = N-1;

        while(l<r) {
            answer = max(answer, t[l]+t[r]);
            l++;
            r--;
        }
    }
    else {
        answer = t[N-1];
        int l = 0;
        int r = N-2;

        while(l<r) {
            answer = max(answer, t[l]+t[r]);
            l++;
            r--;
        }
    }

    cout << answer;
}