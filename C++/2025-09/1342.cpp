#include <iostream>
#include <algorithm>
using namespace std;

bool isLucky(string& ss) {
    for(int i=1;i<ss.length();i++) {
        if(ss[i] == ss[i-1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    sort(S.begin(), S.end());

    long long count = 0;
    do {
        if (isLucky(S)) count++;
    } while (next_permutation(S.begin(), S.end()));

    cout << count;
}