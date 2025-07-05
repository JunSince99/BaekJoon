#include <iostream>
using namespace std;

int N;

bool isPrime(int num) {
    if (num<2) return false;
    for(int i=2;i*i<=num;i++) {
        if(num%i == 0) return false;
    }
    return true;
}

void dfs(int num, int depth) {
    if(depth == N) {
        cout << num << '\n';
        return;
    }

    for(int i=1;i<=9;i++) {
        int nxt = num*10 + i;
        if(isPrime(nxt)) dfs(nxt, depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}