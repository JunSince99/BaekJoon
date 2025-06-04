#include <iostream>
#include <algorithm>
using namespace std;

int fir = 1e9;
int sec = 1e9;
int N;
int liq[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> liq[i];
    
    for(int i=0;i<N;i++) {
        //제일 가까운 lower_뭐시기 찾고 그 앞뒤 비교
        int idx = lower_bound(liq,liq+N,-liq[i]) - liq;
        if(idx < N && i != idx && abs(liq[i]+liq[idx]) < abs(fir+sec)) {
            fir = liq[i];
            sec = liq[idx];
        }
        if(idx != 0 && i != idx-1 && abs(liq[i]+liq[idx-1]) < abs(fir+sec)) {
            fir = liq[i];
            sec = liq[idx-1];
        }
        if(idx+1 < N && i != idx+1 && abs(liq[i]+liq[idx+1]) < abs(fir+sec)) {
            fir = liq[i];
            sec = liq[idx+1];
        }
    }
    if(sec<fir) swap(fir, sec);
    cout << fir << ' ' << sec << '\n';
}