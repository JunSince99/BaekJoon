#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;

    if(N%7 == 2 || N%7 == 0) cout << "CY" << endl;
    else cout << "SK" << endl;

    return 0;
}