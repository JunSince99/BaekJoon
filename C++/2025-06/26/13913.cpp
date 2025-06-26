#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 200001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    vector<int> dist(INF, -1);
    vector<int> parent(INF, -1);

    queue<int> q;
    q.push(N);
    dist[N] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if(cur == K) break;

        for(int nxt : {cur+1, cur-1, cur*2}) {
            if(0<=nxt && nxt<INF && dist[nxt] == -1) {
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
                parent[nxt] = cur;
            }
        }
    }

    cout << dist[K] << '\n';

    vector<int> road;

    for(int i=K;i != -1; i = parent[i])
        road.push_back(i);

    for(int i=road.size()-1;i>=0;i--)
        cout << road[i] << ' ';
}