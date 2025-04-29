#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    map<int, vector<int>> link;

    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    int minper;
    int minlink = 1e9;

    for(auto l:link) {
        queue<pair<int,int>> q;
        vector<bool> visited(N+1, false);
        int kevin = 0;
        visited[l.first] = true;
        
        q.push({l.first,0});
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for(auto to :link[cur.first]) {
                if(!visited[to]) {
                    q.push({to,cur.second+1});
                    visited[to] = true;
                    kevin += cur.second+1;
                }
            }
        }
        if(kevin < minlink) {
            minper = l.first;
            minlink = kevin;
        }
    }

    cout << minper << '\n';
}