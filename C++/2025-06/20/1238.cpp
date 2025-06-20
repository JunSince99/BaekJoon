#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N,M,X;
vector<pair<int,int>> adj[1001];

vector<int> dij(int ver) {
    vector<int> d(N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[ver] = 0;
    pq.push({0,ver});
    while(!pq.empty()) {
        int curT = pq.top().first;
        int curV = pq.top().second;
        pq.pop();

        if(curT != d[curV]) continue;
        for(auto& nxt : adj[curV]) {
            int nxtT = nxt.first;
            int nxtV = nxt.second;
            if(nxtT + d[curV] < d[nxtV]) {
                d[nxtV] = nxtT + d[curV];
                pq.push({d[nxtV],nxtV});
            }
        } 
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    for(int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }

    vector<int> rever = dij(X);
    int ans=0;
    for(int i=1;i<=N;i++) {
        vector<int> curd = dij(i);
        ans = max(ans,curd[X]+rever[i]);
    }

    cout << ans;
}