#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> town(N);
        for (int i = 0; i < N; i++) {
            cin >> town[i];
        }

        int money = 0;
        for (int i = 0; i < M; i++) {
            money += town[i];
        }

        int count = 0;
        if (money < K) count++;

        if (N == M) {
            cout << count << '\n';
            continue;
        }

        for (int i = 1; i < N; i++) {
            money = money - town[i - 1] + town[(i + M - 1) % N];
            if (money < K) count++;
        }

        cout << count << '\n';
    }

    return 0;
}