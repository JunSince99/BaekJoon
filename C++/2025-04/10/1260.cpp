#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

vector<vector<int>> graph;
vector<bool> visited_bfs;
vector<bool> visited_dfs;

void dfs(int v) {
    cout << v << " ";
    visited_dfs[v] = true;

    for(int e : graph[v]) {
        if(!visited_dfs[e]) {
            dfs(e);
        }
    }
}

void bfs(int v) {
    cout << v << " ";
    visited_bfs[v] = true;

    queue<int> q;
    for(int e : graph[v]) {
        q.push(e);
        visited_bfs[e] = true;
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for(int e: graph[cur]) {
            if (!visited_bfs[e]) {
                q.push(e);
                visited_bfs[e] = true;
            }
        }
    }
}

int main() {
    int N,M,V;
    cin >> N >> M >> V;

    graph.resize(N+1);
    visited_bfs.resize(N+1);
    visited_dfs.resize(N+1);
    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(vector<int>& vertex:graph) {
        sort(vertex.begin(),vertex.end());
    }

    dfs(V);
    cout << '\n';

    bfs(V);
    cout << '\n';

    return 0;
}