#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> result;

void dfs(int cur, int depth) {
    if(depth == M) {
        for(int i=0;i<M;i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=cur;i<=N;i++) {
        result.push_back(i);
        dfs(i,depth+1);
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> N >> M;
    dfs(1,0);
    return 0;
}