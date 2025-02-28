#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int first = 1, second = 2;
    if (n == 1) {
        cout << first << endl;
        return 0;
    } else if (n == 2) {
        cout << second << endl;
        return 0;
    } else {
        for(int i = 0; i < n-2; i++) {
            int temp = (first + second) % 10007;
            first = second;
            second = temp;
        }
        cout << second << endl;
        return 0;
    }
}