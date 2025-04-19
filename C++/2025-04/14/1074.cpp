#include <iostream>

using namespace std;

int cnt = 0;

void Z(int N, int r, int c) {
    int half = 1 << (N - 1);

    int cur = half * half;
    
    if (r<half && c<half) { //2사분면
        if (N == 1) {
            return;
        } else {
            Z(N-1, r, c);
        }
    } else if (r<half && c>=half) { //1사분면
        if (N == 1) {
            cnt += 1;
            return;
        } else {
            cnt += cur;
            Z(N-1, r, c-half);
        }
    } else if (r>=half && c < half) { //3사분면
        if (N == 1) {
            cnt += 2;
            return;
        } else {
            cnt += cur*2;
            Z(N-1, r-half, c);
        }
    } else if (r>=half && c>=half) { //4사분면
        if (N == 1) {
            cnt += 3;
            return;
        } else {
            cnt += cur*3;
            Z(N-1, r-half, c-half);
        }
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    Z(N,r,c);

    cout << cnt << '\n';
}