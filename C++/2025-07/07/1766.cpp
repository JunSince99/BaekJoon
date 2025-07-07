#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> adj[32001];
int parent[32001];
vector<int> order[32001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        parent[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=1;i<=N;i++)
        if(parent[i] == 0) q.push(i);
    
    while(!q.empty()) {
        int cur = q.top();q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            parent[nxt]--;
            if(parent[nxt] == 0) q.push(nxt);
        }
    }
}