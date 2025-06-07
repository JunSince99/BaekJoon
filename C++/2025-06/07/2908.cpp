#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int a=0;
    int b=0;

    a += A[0] - '0';
    a += (A[1] - '0') * 10;
    a += (A[2] - '0') * 100;

    b += B[0] - '0';
    b += (B[1] - '0') * 10;
    b += (B[2] - '0') * 100;
    cout << max(a,b);
}