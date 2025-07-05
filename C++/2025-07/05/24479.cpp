#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,R;
vector<int> P[100001];
int visited[100001];
int order = 1;

void dfs(int cur) {
    visited[cur] = order++;

    for(int& p:P[cur]) {
        if(visited[p] == 0) {
            dfs(p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    while(M--) {
        int a,b;
        cin >> a >> b;
        P[a].push_back(b);
        P[b].push_back(a);
    }

    for (int i=1; i<=N;i++) {
        sort(P[i].begin(), P[i].end());
    }

    dfs(R);

    for(int i=1;i<=N;i++) {
        cout << visited[i] << '\n';
    }
}