#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> result;
vector<int> numbers;
bool visited[8] = {false};

void dfs(int depth) {
    if(depth == M) {
        for(int i=0;i<M;i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0;i<N;i++) {
        if(!visited[i]) {
            visited[i] = true;
            result.push_back(numbers[i]);
            dfs(depth+1);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int n;
        cin >> n;
        numbers.push_back(n);
    }
    sort(numbers.begin(), numbers.end());
    dfs(0);
    return 0;
}