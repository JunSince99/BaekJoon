#include <iostream>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int five = n / 5;

    while(five>=0) {
        if((n-five*5) % 2 == 0) {
            cout << five + (n - five * 5) / 2;
            return 0;
        } else {
            five--;
        }
    }

    cout << -1;
}