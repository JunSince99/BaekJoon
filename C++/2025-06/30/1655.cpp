#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left;
    while(n--) {
        int cur;
        cin >> cur;

        if(left.empty() || cur<=left.top())
            left.push(cur);
        else
            right.push(cur);

        if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        } else if(right.size()+1<left.size()) {
            right.push(left.top());
            left.pop();
        }

        cout << left.top() << '\n';
    }
}