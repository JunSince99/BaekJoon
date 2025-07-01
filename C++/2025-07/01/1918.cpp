#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<char> st;
    string pex;
    cin >> pex;
    for(char& p : pex) {
        if('A' <= p && p <= 'Z') cout << p;
        else if(p == '(') st.push(p);
        else if(p == ')') {
            while(st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(p)) {
                cout << st.top();
                st.pop();
            }
            st.push(p);
        }
    }

    while(!st.empty()) {
        cout << st.top(); st.pop();
    }
}