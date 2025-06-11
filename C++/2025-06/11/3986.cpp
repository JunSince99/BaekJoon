#include <iostream>
#include <stack>
using namespace std;

int N, cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        string word;
        cin >> word;
        stack<char> st;
        for(char& c : word) {
            if(st.empty()) st.push(c);
            else {
                if(st.top() == c) st.pop();
                else st.push(c);
            }
        }
        if(st.empty()) cnt++;
    }
    cout << cnt;
}