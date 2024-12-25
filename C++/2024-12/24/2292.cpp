#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int far = 1;
    int cnt = 0;
    while(6*cnt+1 < N) {
        cnt += far++;
    }
    cout << far << endl;

    return 0;
}