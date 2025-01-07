#include <iostream>
#include <stack>

using namespace std;

int main() {
    int K;
    cin >> K;

    stack<int> st;
    for(int i=0;i<K;i++) {
        int num;
        cin >> num;

        if (num == 0) {
            st.pop();
        } else {
            st.push(num);
        }
    }

    int answer = 0;
    while(!st.empty()) {
        answer += st.top();
        st.pop();
    }

    cout << answer << endl;

    return 0;
}