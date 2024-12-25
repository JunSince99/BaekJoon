#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    long long answer = 0;
    long long myPow = 1;
    for(char &s:S) {
        int ss = s - 'a' + 1;

        answer =  (answer + ss * myPow) % 1234567891;
        myPow = (myPow*31)%1234567891;
    }

    cout << answer << endl;

    return 0;
}