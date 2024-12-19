#include <iostream>

using namespace std;

int main() {
    int max=0;
    int cnt;
    for (int i=1;i<10;i++) {
        int num;
        cin >> num;
        if (num>max) {
            max = num;
            cnt = i;
        }
    }
    cout << max << endl;
    cout << cnt << endl;
}