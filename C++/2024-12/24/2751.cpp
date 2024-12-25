#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> rray(n);
    for(int i=0;i<n;i++) {
        cin >> rray[i];
    }
    sort(rray.begin(),rray.end());

    for(int i=0;i<n;i++) {
        cout << rray[i] << '\n';
    }

    return 0;
}