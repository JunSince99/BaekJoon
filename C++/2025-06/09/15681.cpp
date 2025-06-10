#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N,R,Q;
unordered_map<int, vector<int>> um;
int vercnt[100001];

int dfs(int parent, int cur) {
    int cnt = 1;
    for(int& ver:um[cur]) {
        if(ver == parent) continue;
        cnt += dfs(cur, ver);
    }
    vercnt[cur] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    for(int i=0;i<N-1;i++) {
        int u, v;
        cin >> u >> v;
        um[u].push_back(v);
        um[v].push_back(u);
    }

    dfs(0,R);

    while(Q--) {
        int q;
        cin >> q;
        cout << vercnt[q] << '\n';
    }
}