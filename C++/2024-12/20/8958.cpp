#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        string S;
        cin >> S;
        int point = 0;
        int add_point = 0;
        for(char s:S) {
            if (s=='O') {
                add_point += 1;
                point += add_point;
            } else if (s=='X') {
                add_point = 0;
            }
        }

        cout << point << endl;
    }
}