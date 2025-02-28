#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<pair<int, int>> q; //연산횟수, N
    q.push({0, N});
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.second == 1) {
            cout << cur.first << endl;
            return 0;
        } else {
            if (cur.second % 3 == 0) {
                q.push({cur.first+1, cur.second/3});
            }
            if (cur.second % 2 == 0) {
                q.push({cur.first+1, cur.second/2});
            }
            q.push({cur.first+1, cur.second-1});
        }
    }
}