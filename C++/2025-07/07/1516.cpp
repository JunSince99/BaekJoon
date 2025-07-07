#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<int> buildings[501];
int last[501]; // 부모 갯수
int times[501]; // 각 건물 시간
int answer[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    cin >> N;
    for(int i=1;i<=N;i++) {
        int cur;
        cin >> cur;
        times[i] = cur;
        answer[i] = cur;
        while(true) {
            int to;
            cin >> to;
            if(to == -1) break;

            last[i]++;
            buildings[to].push_back(i);
        }
        if(last[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int nxt : buildings[cur]) {
            answer[nxt] = max(answer[nxt], answer[cur] + times[nxt]);
            last[nxt]--;
            if(last[nxt] == 0) q.push(nxt);
        }
    }

    for(int i=1;i<=N;i++) {
        cout << answer[i] << '\n';
    }
}