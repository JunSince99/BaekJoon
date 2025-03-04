#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int n=0; n<N; n++) {
        int x;
        cin >> x;
        if(x==0) {
            if(minheap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << minheap.top() << '\n';
                minheap.pop();
            }
        } else {
            minheap.push(x);
        }
    }

    return 0;
}