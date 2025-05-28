#include <iostream>

using namespace std;

void tri(int n) {
    if (n == 3) {
        cout << "  *  " << '\n';
        cout << " * * " << '\n';
        cout << "*****" << '\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    tri(n);
}