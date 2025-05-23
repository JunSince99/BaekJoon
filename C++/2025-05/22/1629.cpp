#include <iostream>

using namespace std;

long long dp(long long A, long long B, long long C) {
    if(B==1) {
        return A % C;
    }
    long long temp = dp(A,B/2,C);
    if(B % 2 == 0) {
        return (temp*temp) % C;
    } else {
        return (temp*temp % C) * (A % C) % C;
    }
}

int main() {
    long long a,b,c;
    cin >> a >> b >>c;

    cout << dp(a,b,c) << '\n';

    return 0;
}