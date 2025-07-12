#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> relation[2000];
bool visited[2000];

bool dfs(int cur, int depth) {
    if (depth == 5) {
        return true;
    }

    for(int nxt:relation[cur]) {
        if(!visited[nxt]) {
            visited[nxt] = true;
            if(dfs(nxt, depth+1)) {
                return true;
            }
            visited[nxt] = false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int a,b;
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    for(int i=0;i<N;i++) {
        visited[i] = true;
        if(dfs(i,1)) {
            cout << 1;
            return 0;
        }
        visited[i] = false;
    }
    cout << 0;
}