#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<pair<int,int>> st;
    vector<int> NGE(N,-1);
    for(int i=0;i<N;i++) {
        int a;
        cin >> a;

        while(!st.empty() && a > st.top().first) {
            NGE[st.top().second] = a;
            st.pop();
        }

        st.push({a,i});
    }
    for(int& n:NGE) {
        cout << n << ' ';
    }
}