#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> ans(N,0);
    stack<pair<int,int>> st;
    for(int i=0;i<N;i++) {
        int to;
        cin >> to;
        if(st.empty()) {
            st.push({to,i});
            continue;
        }

        while(!st.empty() && st.top().first < to) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top().second+1;
        }
        st.push({to,i});
    }

    for(int i=0;i<N;i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}