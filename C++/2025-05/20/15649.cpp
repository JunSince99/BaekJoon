#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> result;
bool visited[9];

void backtrack(int depth) {
    if (depth == M) {
        for (int i = 0;i<M;i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++) {
        if(!visited[i]) {
            visited[i] = true;
            result.push_back(i);
            backtrack(depth + 1);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    backtrack(0);
    return 0;
}