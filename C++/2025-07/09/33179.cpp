#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        string a;
        cin >> a;
        cout << (a[0] - '0') + (a[2] - '0') << '\n';
    }
}