#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    int start, end;
    cin >> start >> end;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, INF);
    dist[start] = 0;

    pq.push({start,0});
    while(!pq.empty()) {
        int cur = pq.top().first;
        int cur_cost = pq.top().second;
        pq.pop();

        if(dist[cur] < cur_cost) continue;

        for(const auto &edge : graph[cur]) {
            int next = edge.first;
            int next_cost = cur_cost+edge.second;

            if(dist[next] > next_cost) {
                dist[next] = next_cost;
                pq.push({next,next_cost});
            }
        }
    }

    cout << dist[end] << '\n';
    return 0;
}