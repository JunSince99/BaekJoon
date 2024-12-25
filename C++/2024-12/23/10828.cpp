#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> stck;
    int N;
    cin >> N;
    for(int n=0;n<N;n++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            stck.push(num);
        } else if (cmd == "pop") {
            if(!stck.empty()) {
                cout << stck.top() << endl;
                stck.pop();
            } else {
                cout << -1 << endl;
            }

            
        } else if (cmd == "size") {
            cout << stck.size() << endl;
        } else if (cmd == "empty") {
            stck.empty() ? cout << 1 << endl : cout << 0 << endl;
        } else if (cmd == "top") {
            stck.empty() ? cout << -1 << endl : cout << stck.top() << endl;
        }
    }
}