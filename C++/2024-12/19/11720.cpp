#include <iostream>

using namespace std;

int answer = 0;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    for (int i=0;i<N;i++) {
        int a = S[i] - '0';
        answer += a;
    }
    cout << answer << endl;

    return 0;
}