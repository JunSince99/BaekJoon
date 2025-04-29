#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ract(n+1);

    ract[1] = 1;
    ract[2] = 3;
    
    for(int i=3;i<n+1;i++) {
        ract[i] = (ract[i-1] + (ract[i-2]*2)) % 10007;
    }

    cout << ract[n] << '\n';
}