#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0;t<T;t++) {
        int r;
        string S;
        string P = "";
        cin >> r >> S;
        for(char s:S) {
            for (int i=0;i<r;i++) {
                P = P + s;
            }
        }
        cout << P << endl;
    }
}