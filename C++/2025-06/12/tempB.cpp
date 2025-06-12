#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C;
    cin >> A >> B >> C;
    int cnt;
    if(A == 2015) {
        cnt++;
        if(B>=3) cnt++;
        if(B>=6) cnt++;
        if(B>=9) cnt++;
        if(B>=12) cnt++;
        cout << cnt << '\n';
        return 0;
    }
    if(A == 2016) {
        cnt = 5;
        if(B>=3) cnt++;
        if(B>=6) cnt++;
        if(B>=9) cnt++;
        if(B>=12) cnt++;
        cout << cnt << '\n';
        return 0;
    }
    cnt = (A-2015-1) * 4 + 5;
    if(B>=3) cnt++;
    if(B>=6) cnt++;
    if(B>=9) cnt++;
    if(B>=12) cnt++;
    cout << cnt << '\n';
    return 0;
}