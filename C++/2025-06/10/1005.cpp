#include <iostream>
using namespace std;

int T;
int N,K;
int D[1001];
int Dtime[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i=1;i<=N;i++) cin >> D[i];
    }
}

//위상 정렬이 필요해서 일단 다른 문제 부터!