#include <iostream>
#include <vector>
using namespace std;

int N, M;
int visited[10];
int answer[10];

void recur(int n) {
    if(n == M) {
        for(int i=0;i<M;i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++) {
        if(!visited[i]) {
            visited[i] = true;
            answer[n]=i;
            recur(n+1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    recur(0);
}