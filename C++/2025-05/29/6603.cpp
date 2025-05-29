#include <iostream>
using namespace std;

int k;
int S[13];
int answer[6];

void recur(int depth, int cur) {
    if (depth == 6){
        for(int i=0;i<6;i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=cur;i<k;i++) {
        answer[depth] = S[i];
        recur(depth+1, i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> k;
        if(k==0) break;
        for(int i=0;i<k;i++) cin >> S[i];
        recur(0,0);
        cout << '\n';
    }
}