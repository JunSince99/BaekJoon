#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N,M;
set<vector<int>> result;
vector<int> numbers;
bool visited[8] = {false};
vector<int> temp;

void dfs(int depth) {
    if(depth == M) {
        result.insert(temp);
        return;
    }
    for(int i=0;i<N;i++) {
        if(!visited[i]) {
            visited[i] = true;
            temp.push_back(numbers[i]);
            dfs(depth+1);
            temp.pop_back();
            visited[i] = false;
        }
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
    dfs(0);

    for(vector<int> tmp : result) {
        for(int num : tmp) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}