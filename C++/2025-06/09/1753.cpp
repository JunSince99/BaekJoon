#include <iostream>
#include <queue>
using namespace std;

const int INF = 2e9;
int V,E,K;
vector<pair<int,int>> adj[20001]; // 정점, 간선, 가중치 저장
int d[20001]; // 최단 거리 테이블

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;
    fill(d,d+V+1,INF);
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    d[K] = 0;
    pq.push({0,K});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.first != d[cur.second]) continue;
        for(auto nxt : adj[cur.second]) {
            if(d[nxt.second] > d[cur.second] + nxt.first) {
                d[nxt.second] = d[cur.second] + nxt.first;
                pq.push({d[nxt.second], nxt.second});
            }
        }
    }

    for(int i=1;i<=V;i++) {
        if(d[i] == 2e9) {
            cout << "INF" << '\n';
            continue;
        }
        cout << d[i] << '\n';
    }
}