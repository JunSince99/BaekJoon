#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, E;
vector<pair<int,int>> adj[801];

vector<int> dijk(int K) {
    vector<int> d(N+1, INF);
    d[K] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,K});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.first != d[cur.second]) continue;
        for(auto& nxt : adj[cur.second]) {
            if(nxt.first + d[cur.second]<d[nxt.second]) {
                d[nxt.second] = nxt.first + d[cur.second];
                pq.push({d[nxt.second], nxt.second});
            }
        }
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 1 -> N까지 가는 경로 중
    // v1, v2를 통과하는 경로 중 거리 최소값.
    // 1->v1->v2->N
    // 1->v2->v1->N
    // 따라서 1출발, v1출발, v2출발의 거리 테이블 3개 구하고
    // 저 둘중 작은거 출력하면 됨

    cin >> N >> E;
    for(int i=0;i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    int v1,v2;
    cin >> v1 >> v2;

    vector<int> d1 = dijk(1);
    vector<int> dv1 = dijk(v1);
    vector<int> dv2 = dijk(v2);

    long long ans1 = (long long)d1[v1] + dv1[v2] + dv2[N];
    long long ans2 = (long long)d1[v2] + dv2[v1] + dv1[N];

    if(ans1>=INF && ans2>=INF) {
        cout << -1 << '\n';
    } else {
        cout << min(ans1,ans2) << '\n';
    }
}