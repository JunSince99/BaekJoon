#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i=0;i<T;i++) {
        string ps;
        cin >> ps;
        stack<char> st;
        for (const char & s:ps) {
            if(!st.empty() && s == ')' && st.top() == '(') {
                st.pop();
            } else {
                st.push(s);
            }
        }
        if(st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}