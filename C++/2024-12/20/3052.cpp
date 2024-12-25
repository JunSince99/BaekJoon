#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int cnt[42] = {0};
    for (int i=0;i<10;i++) {
        int input;
        cin >> input;
        cnt[input%42] += 1;
    }

    for (int c:cnt) {
        if(c!=0) answer+=1;
    }

    cout << answer << endl;

    return 0;
}