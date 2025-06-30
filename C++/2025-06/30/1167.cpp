#include <iostream>
#include <vector>
using namespace std;

int maxver, maxLen;
int V;
vector<pair<int,int>> adj[100001];
bool visited[100001];

void dfs(int cur, int depth) {
    if(visited[cur]) return;

    visited[cur] = true;
    if(depth>maxLen) {
        maxLen = depth;
        maxver = cur;
    }

    for(auto& nxt:adj[cur]) {
        dfs(nxt.first, depth+nxt.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V;
    for(int i=1;i<=V;i++) {
        int from;
        cin >> from;
        while(true) {
            int to, cost;
            cin >> to;
            if(to == -1) break;
            cin >> cost;

            adj[from].push_back({to,cost});
        }
    }

    dfs(1,0);

    maxLen=0;
    fill(visited, visited+V+1,false);

    dfs(maxver, 0);
    cout << maxLen;
}