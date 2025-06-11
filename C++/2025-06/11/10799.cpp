#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    string pipes;
    cin >> pipes;
    stack<char> st;

    bool islastopen = false;
    for(char& c : pipes) {
        if(st.empty() && c == '(') {
            st.push(c);
            islastopen = true;
        } else {
            if(c == '(') {
                st.push(c);
                islastopen = true;
            } else {
                if(islastopen) {
                    st.pop();
                    cnt += st.size();
                    islastopen = false;
                } else {
                    st.pop();
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}