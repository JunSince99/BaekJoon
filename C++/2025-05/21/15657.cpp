#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> result;
vector<int> numbers;

void dfs(int cur,int depth) {
    if(depth == M) {
        for(int i=0;i<M;i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=cur;i<N;i++) {
        result.push_back(numbers[i]);
        dfs(i,depth+1);
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int n;
        cin >> n;
        numbers.push_back(n);
    }
    sort(numbers.begin(), numbers.end());
    dfs(0,0);
    return 0;
}