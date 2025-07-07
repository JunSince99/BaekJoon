#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll minval, maxval;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> minval >> maxval;

    vector<bool> isnono(maxval-minval+1, false);

    for(ll i=2;i*i<=maxval;i++) {
        ll square = i*i;
        ll start = (minval+square-1) / square * square;

        while(start<=maxval) {
            isnono[start-minval] = true;
            start += square;
        }
    }
    int cnt=0;

    for(bool no : isnono) {
        if(!no) cnt++;
    }

    cout << cnt;
}