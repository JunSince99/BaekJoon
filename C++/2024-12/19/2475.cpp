#include <iostream>

using namespace std;

int main() {
    int answer=0;
    for (int i=0;i<5;i++) {
        int num;
        cin >> num;

        answer += num*num;
    }

    cout << answer%10 << endl;

    return 0;
}