#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> store;
bool visited[9];

void backtrack(int depth) {
    if (depth == n) {
        for(int a:store) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            store.push_back(i);
            visited[i] = true;
            backtrack(depth+1);
            store.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    backtrack(0);
}