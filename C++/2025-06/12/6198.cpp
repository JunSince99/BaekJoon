#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    long long cnt = 0;
    cin >> N;
    stack<int> st;
    for(int i=0;i<N;i++) {
        int h;
        cin >> h;

        while(!st.empty() && h >= st.top()) {
            st.pop();
        }
        if(!st.empty()) cnt += st.size();
        st.push(h);
    }
    cout << cnt;
}