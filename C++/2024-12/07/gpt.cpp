#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100000;

int bfs(int start, int target) {
    vector<int> time(MAX + 1, -1); // 방문 여부 및 시간을 저장
    queue<int> q;
    
    time[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 동생을 찾으면 그 시점의 시간을 반환
        if (current == target) {
            return time[current];
        }
        
        // 순간이동: 2 * current
        if (current * 2 <= MAX && time[current * 2] == -1) {
            time[current * 2] = time[current];
            q.push(current * 2);
        }
        
        // 걷기: current - 1
        if (current - 1 >= 0 && time[current - 1] == -1) {
            time[current - 1] = time[current] + 1;
            q.push(current - 1);
        }
        
        // 걷기: current + 1
        if (current + 1 <= MAX && time[current + 1] == -1) {
            time[current + 1] = time[current] + 1;
            q.push(current + 1);
        }
    }
    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
    return 0;
}