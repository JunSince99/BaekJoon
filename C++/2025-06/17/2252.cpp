#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> graphs[32001];
int idg[32001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graphs[a].push_back(b);
        idg[b]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) if(idg[i]==0) q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int g : graphs[cur]) {
            idg[g]--;
            if(idg[g] == 0) q.push(g);
        }
    }
}