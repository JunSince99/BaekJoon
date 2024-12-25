#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a,b,v;
    cin >> a >> b >> v;

    cout << ceil((v-a)/(a-b)) + 1 << '\n';

    return 0;
}