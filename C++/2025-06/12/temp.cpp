#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    unordered_map<int,int> um; 
    for(int i=1;i*i<=1000000000;i++) {
        um[i*i] = 1;
    }

    while(T--) {
        int n;
        cin >> n;
        if(um[n]==1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}