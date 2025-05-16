#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int,vector<int>> maps;
    vector<vector<int>> way(N,vector<int>(N,0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int x;
            cin >> x;
            if (x == 1) {
                maps[i].push_back(j);
            }
        }
    }

    for(int i=0;i<N;i++) {
        queue<int> q;

        for(int a:maps[i]) {
            q.push(a);
            way[i][a] = 1;
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int a:maps[cur]) {
                if (!way[i][a]) {
                    q.push(a);
                    way[i][a] = 1;
                }
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << way[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}