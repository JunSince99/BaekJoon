#include <iostream>
#include <queue>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    queue<pair<long long,int>> q;
    q.push({A,1});

    while(!q.empty()) {
        long long cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(cur == B) {
            cout << depth << '\n';
            return 0;
        }

         long long one = cur * 2;
         long long two = cur * 10 + 1;

        if(one <= B) {
            q.push({one,depth+1});
        }
        if(two <= B) {
            q.push({two,depth+1});
        }
    }
    cout << -1 << '\n';
}