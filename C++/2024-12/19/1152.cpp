#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    bool lastwasblank = true;
    string S;
    getline(cin, S);
    for (char s:S) {
        if(s!=' ' && lastwasblank) answer++;
        if(s==' ') lastwasblank = true;
        else lastwasblank = false;
    }

    cout << answer << endl;
    return 0;
}