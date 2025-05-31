#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans;
int S[8];
int W[8];

void recur(int idx) {
    if(idx==N) {
        int cnt = 0;
        for(int i=0;i<N;i++) {
            if (S[i]<=0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    if (S[idx] <= 0) {
        recur(idx + 1);
        return;
    }

    bool ishit = false;
    for(int i=0;i<N;i++) {
        if(i == idx) continue;
        if(S[i]<=0) continue;

        //깨고 recur 깬거복구
        ishit = true;
        S[i] -= W[idx];
        S[idx] -= W[i];
        recur(idx+1);
        S[i] += W[idx];
        S[idx] += W[i];
    }
    if(!ishit) recur(idx+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++)
        cin >> S[i] >> W[i];

    recur(0);
    cout << ans;
}