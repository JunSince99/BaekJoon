#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int answer = 0;

    for (int i=5;i<=N;i*=5) {
        answer += N/i;
    }

    cout << answer << endl;

    return 0;
}