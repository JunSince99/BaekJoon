#include <iostream>

using namespace std;

int main() {
    int code[8];
    for(int i=0;i<8;i++) {
        cin >> code[i];
    }

    int compare = code[0];
    string answer;

    for(int i=1;i<8;i++) {
        if (compare - code[i] == 1) {
            answer = "descending";
            compare = code[i];
        } else if (compare - code[i] == -1) {
            answer = "ascending";
            compare = code[i];
        } else {
            cout << "mixed" << endl;
            return 0;
        }
    }
    cout << answer << endl;
}