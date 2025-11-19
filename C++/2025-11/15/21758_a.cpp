#include <iostream>
#include <algorithm>
using namespace std;

int N;
int land[100000];
long long psum[100000];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> land[i];
        if(i==0) psum[i] = land[i];
        else psum[i] = psum[i-1] + land[i];
    }

    long long answer = 0;

    for(int i=1;i<N-1;i++) {
        long long left = 2 * psum[N-1] - psum[0] - psum[i] - land[i];
        answer = max(answer, left);
        long long right = psum[N-2] + psum[i-1] - land[i];
        answer = max(answer, right);
        long long mid = (psum[i]-psum[0]) + (psum[N-2] - psum[i-1]);
        answer = max(answer, mid);
    }

    cout << answer;
}