#include <iostream>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    if (N>0 && M>0) {
        cout << N/M << '\n' << N%M << '\n';
    }
   

    return 0;
}