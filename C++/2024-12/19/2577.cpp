#include <iostream>

using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    int cnt[10] = {0};
    string N = to_string(A*B*C);
    for (char n:N) {
        int num = n - '0';
        cnt[num] += 1;
    }
    for (int i=0;i<10;i++) {
        cout << cnt[i] << endl;
    }
}