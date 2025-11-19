#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int population[10];
vector<int> adj[10];

bool isConnect(int mask, bool isA) {
    // 확인할 노드 목록 vector 선언
    vector<int> nodes;
    // vector에 isA에 따라 적절하게 추가
    for(int i=0;i<N;i++) {
        bool isone = (mask & (1<<i));

        if(isA && isone) nodes.push_back(i);
        if(!isA && !isone) nodes.push_back(i);
    }

    if (nodes.empty()) return false;

    queue<int> q;
    vector<bool> visited(N,false);

    q.push(nodes[0]);
    visited[nodes[0]] = true;

    int cnt = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt:adj[cur]) {
            bool isone = mask & (1<<nxt);

            if(isA && !isone) continue;
            if(!isA && isone) continue;

            if(!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                cnt++;
            }
        }
    }

    return cnt == (int)nodes.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) cin >> population[i];
    for(int i=0;i<N;i++) {
        int t;
        cin >> t;
        for(int j=0;j<t;j++) {
            int a;
            cin >> a;
            adj[i].push_back(a-1);
        }
    }

    int answer = 1e9;

    for(int mask = 1; mask<(1<<N)-1;mask++) { // ~0001 부터 ~1110 까지 뽑으면 선거구 종류는 다 뽑은거고,
        //isConnect가 서로 연결돼있는지만 확인해주면 인구수만 더해보면 됨
        if(!isConnect(mask, true)) continue;
        if(!isConnect(mask, false)) continue;

        // 인구수 확인
        int sumA = 0;
        int sumB = 0;
        for(int i=0;i<N;i++) {
            if(mask & (1<<i)) sumA += population[i];
            else sumB += population[i];
        }

        answer = min(answer, abs(sumB-sumA));
    }

    if (answer == 1e9) cout << -1;
    else cout << answer;
}