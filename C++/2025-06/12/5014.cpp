#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    if(S==G) {
        cout << 0 << '\n';
        return 0;
    }

    queue<pair<int,int>> q; //cur, cnt;
    vector<bool> visited(F+1,false);
    q.push({S,0});
    visited[S] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        int up = cur+U;
        int down = cur-D;

        if(0<up && up<=F && !visited[up]) {
            if(up == G) {
                cout << cnt + 1 << '\n';
                return 0;
            }
            q.push({up,cnt+1});
            visited[up] = true;
        }
        if(0<down && down<=F && !visited[down]) {
            if(down == G) {
                cout << cnt + 1 << '\n';
                return 0;
            }
            q.push({down, cnt+1});
            visited[down] = true;
        }
    }
    cout << "use the stairs" << '\n';
}