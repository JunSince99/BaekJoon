#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long cnt=0;
    cin >> N;
    stack<pair<int,int>> st;
    while(N--) {
        int person;
        cin >> person;

        int group = 1;
        while(!st.empty() && person >= st.top().first) {
            cnt += st.top().second;

            if(st.top().first == person)
                group += st.top().second;

            st.pop();
        }
        if(!st.empty()) cnt++;
        st.push({person,group});
    }

    cout << cnt;
}