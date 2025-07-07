#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n,m;
vector<pair<int,int>> adj[1001];
int cost[1001];
int precity[1001];

void dijk(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    cost[start] = 0;
    precity[start] = -1;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [dist, cur] = pq.top(); pq.pop();

        if(dist != cost[cur]) continue;

        for(auto& nxt : adj[cur]) {
            int nxtDist = nxt.first;
            int nxtCity = nxt.second;
            if(dist+nxtDist < cost[nxtCity]) {
                cost[nxtCity] = dist + nxtDist;
                precity[nxtCity] = cur;
                pq.push({cost[nxtCity], nxtCity});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(cost,cost+n+1,INF);
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    int from, to;
    cin >> from >> to;

    dijk(from);

    cout << cost[to] << '\n';

    int cur = precity[to];
    vector<int> path = {to};
    while(cur != -1) {
        path.push_back(cur);
        cur = precity[cur];
    }

    cout << path.size() << '\n';

    for(int i=path.size()-1;i>=0;i--) {
        cout << path[i] << ' ';
    }
}