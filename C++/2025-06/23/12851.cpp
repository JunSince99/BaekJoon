#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001;
int N, K;
int minTime = -1;
int cnt = 0;
vector<int> visited(MAX,-1); // 시간 기록

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = 0;

    while (!q.empty()) {
        auto [cur, time] = q.front(); q.pop();

        if (cur == K) {
            if (minTime == -1) minTime = time;
            if (time == minTime) cnt++;
        }

        for (int nxt : {cur - 1, cur + 1, cur * 2}) {
            if (nxt < 0 || nxt >= MAX) continue;

            if (visited[nxt] == -1 || visited[nxt] == time + 1) {
                q.push({nxt, time + 1});
                visited[nxt] = time + 1;
            }
        }
    }

    cout << minTime << '\n' << cnt << '\n';
    return 0;
}
