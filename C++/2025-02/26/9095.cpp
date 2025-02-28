#include <iostream>

using namespace std;

int method[11] = {0,1,2,4,7,13,24,44,81,149,274};

int main() {
    int T;
    cin >> T;
    for(int t=0;t<T;t++) {
        int n;
        cin >> n;
        cout << method[n] << endl;
    }
    return 0;
}