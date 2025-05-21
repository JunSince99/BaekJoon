#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> result;
bool visited[9] = {false};

void backtrack(int cur, int depth) {
    if (depth == M) {
        for(int i=0;i<M;i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=cur;i<N;i++) {
        visited[i+1] = true;
        result.push_back(i+1);
        backtrack(i+1,depth+1);
        result.pop_back();
        visited[i+1] = false;
    }
}

int main() {
    cin >> N >> M;
    backtrack(0,0);
    return 0;
}