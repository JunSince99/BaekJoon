#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string A;
string B;

bool isit(string s) {
    stack<char> st;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') {
            st.push('(');
        } else if (s[i] == ')') {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(')');
            }
        }
    }

    if(st.size() == 0) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A;
    cin >> B;

    
}