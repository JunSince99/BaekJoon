#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int snacks[1000000];

bool iscan(int len) {
    if(len==0) return 0;
    long long cnt = 0;
    for(int i=N-1;i>=0;i--) {
        cnt += snacks[i] / len;
        if(cnt>=M) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    int left = 0;
    int right = 0;
    for(int i=0;i<N;i++) {
        cin >> snacks[i];
        right = max(right, snacks[i]);
    } 
    sort(snacks,snacks+N);

    while(left < right) {
        int mid = (left + right+1) / 2;
        if(iscan(mid)) {
            left = mid;
        } else {
            right = mid-1;
        }
    }
    cout << left << '\n';
}