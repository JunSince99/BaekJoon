#include <iostream>

using namespace std;

int facto(int num) {
    int answer = 1;
    for(int i=num;i>1;i--) {
        answer *= i;
    }

    return answer;
}

int main() {
    int N,K;
    cin >> N >> K;

    cout << facto(N) / (facto(N-K)*facto(K)) << endl;

    return 0;
}