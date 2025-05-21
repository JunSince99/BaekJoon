#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<int, vector<int>> m;
    vector<int> parents(N+1);
    vector<bool> visited(N+1,false);
    for(int i=0;i<N-1;i++) {
        int x, y;
        cin >> x >> y;

        m[x].push_back(y);
        m[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int tmp : m[cur]) {
            if(!visited[tmp]) {
                q.push(tmp);
                visited[tmp] = true;
                parents[tmp] = cur;
            }
        }
    }

    for(int i=2;i<=N;i++) {
        cout << parents[i] << '\n';
    }

    return 0;
}