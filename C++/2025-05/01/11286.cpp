#include <iostream>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(int a, int b) const {
        if (abs(a) == abs(b)) return a > b;  // 절댓값 같으면 더 작은 수가 우선
        return abs(a) > abs(b);              // 절댓값 작은 수가 우선
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    priority_queue<int, vector<int>, Compare> pq;

    while(t--) {
        int order;
        cin >> order;

        if(order != 0) {
            pq.push(order);
        } else {
            if(pq.size() != 0) {
                cout << pq.top() << '\n';
                pq.pop();
            } else {
                cout << 0 << '\n';
            }
            
        }
    }

    return 0;
}