#include <iostream>
#include <vector>
using namespace std;

int n, startnode, maxLength, maxnode;
vector<pair<int,int>> node[10001];
bool visited[10001];

void dfs(int cur, int depth) {
    if(visited[cur]) return;

    visited[cur] = true;
    if(depth>maxLength) {
        maxnode = cur;
        maxLength = depth;
    }

    for(const auto& nxt : node[cur]) {
        auto [nextNode, cost] = nxt;
        dfs(nextNode, depth+cost);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;

        node[a].push_back({b,c});
        node[b].push_back({a,c});

        if(i==0) startnode = a;
    }

    dfs(startnode, 0);
    
    maxLength = 0;
    fill(visited,visited+10001,false);

    dfs(maxnode, 0);
    cout << maxLength;
}