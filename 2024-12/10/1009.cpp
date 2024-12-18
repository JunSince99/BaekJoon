#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    for (int t=0;t<testcase;t++) {
        int a,b;
        cin >> a >> b;

        if (a%10==0) {
            cout << 10 << endl;
            continue;
        }

        int arr[4];

        arr[0] = a%10;
        for (int i=1;i<4;i++) {
            arr[i] = (arr[i-1]*a)%10;
        }
        
        if (b % 4 == 0) {
            cout << arr[3] << endl;
        } else {
            cout << arr[b % 4 - 1] << endl;
        }
    }

    return 0;
}