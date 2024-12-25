#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int alpha[26] = {-1};
    fill(alpha, alpha + 26, -1);
    string S;
    cin >> S;
    
    for(int i=0;i<S.size();i++) {
        int cur = S[i] - 'a';
        if(alpha[cur] == -1) {
            alpha[cur] = i;
        }
    }

    for(int i=0;i<26;i++) {
        cout << alpha[i] << ' ';
    }
    cout << '\n';
    return 0;
}