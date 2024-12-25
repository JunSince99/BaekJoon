#include <iostream>

using namespace std;

int main() {
    while (true) {
        string S;
        cin >> S;

        if (S == "0") return 0;
        else {
            int start = 0;
            int end = S.size()-1;
            bool ispelin = true;

            while (start < end) {
                if (S[start++] != S[end--]) {
                    ispelin = false;
                    break;
                }
            }
            if (ispelin) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}