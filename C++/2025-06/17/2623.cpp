#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> G[1001];
int deg[1001];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int mm;
        int pre;
        cin >> mm >> pre;
        for(int i=1;i<mm;i++) {
            int cur;
            cin >> cur;
            G[pre].push_back(cur);
            deg[cur]++;
            pre = cur;
        }
    }

    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int g : G[cur]) {
            deg[g]--;
            if(deg[g] == 0) q.push(g);
        }
    }

    if(ans.size() != n) {
        cout << 0 << '\n';
        return 0;
    }
    for(int a : ans) {
        cout << a << '\n';
    }
}