#include <iostream>
#include <queue>

using namespace std;

struct Locate {
    int loc, second;
};

int main() {
    int N,K;
    cin >> N >> K;

    vector<bool> visited(100001, false);

    queue<Locate> q;
    q.push({N,0});
    while(!q.empty()) {
        Locate cur = q.front();
        q.pop();

        if (cur.loc == K) {
            cout << cur.second << endl;
            return 0;
        }

        if (cur.loc * 2 <= 100000 && !visited[cur.loc * 2]) {
            q.push({cur.loc * 2, cur.second});
            visited[cur.loc * 2] = true;
        }
        if (cur.loc - 1 >= 0 && !visited[cur.loc - 1]) {
            q.push({cur.loc - 1, cur.second + 1});
            visited[cur.loc - 1] = true;
        }
        if (cur.loc + 1 <= 100000 && !visited[cur.loc + 1]) {
            q.push({cur.loc + 1, cur.second + 1});
            visited[cur.loc + 1] = true;
        }
    }
    return 0;
}