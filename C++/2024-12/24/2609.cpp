#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    for (int i=min(a,b);i>0;i--) {
        if (a%i==0 && b%i==0) {
            cout << i << endl;
            break;
        }
    }

    int da = a;
    int db = b;

    while (da != db) {
        if (da>db) {
            db += b;
        } else {
            da += a;
        }
    }
    cout << da << endl;

    return 0;
}