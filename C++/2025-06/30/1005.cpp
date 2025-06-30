#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, N, K, W;
vector<int> adj[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> K;
        int answer = 0;
        int D[1001] {};
        int P[1001] {};
        int dp[1001] {};
        for (int i = 1; i <= N; ++i)
            adj[i].clear();
        
        for(int i=1;i<=N;i++) cin >> D[i];
        for(int i=0;i<K;i++) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            P[b]++;
        }
        cin >> W;

        queue<int> q;
        for(int i=1;i<=N;i++) {
            if(P[i] == 0) {
                q.push(i);
                dp[i] = D[i];
            } 
        }
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            //cout << "now : " << cur << " dp : " << dp[cur] << '\n';
            if(cur == W) break;

            for(int nxt:adj[cur]) {
                P[nxt]--;
                dp[nxt] = max(dp[nxt], dp[cur]+D[nxt]);
                if(P[nxt] == 0) q.push(nxt);
            }
        }

        cout << dp[W] << '\n';
    }
}