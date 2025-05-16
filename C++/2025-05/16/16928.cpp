#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    unordered_map<int, int> snla;
    bool visited[101] = {false};
    for(int i=0;i<N+M;i++) {
        int a, b;
        cin >> a >> b;
        snla[a] = b;
    }

    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        if(cur.first == 100) {
            cout << cur.second << '\n';
            break;
        }

        for(int i=1;i<7;i++) {
            int next = cur.first + i;

            if(0<next && next <= 100 && !visited[next]){
                if(snla.count(next)) {
                    q.push({snla[next], cur.second+1});

                    visited[next] = true;
                    visited[snla[next]] = true;
                } else {
                    q.push({next,cur.second+1});
                    visited[next] = true;
                }
            }
        }
    }

    return 0;
}