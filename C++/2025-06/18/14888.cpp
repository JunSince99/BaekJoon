#include <iostream>
using namespace std;

int n;
int A[11];
int ope[4]; // +, -, *, /
int maxresult = -1e9;
int minresult = 1e9;

void dfs(int idx, int current) {
    if(idx == n) {
        maxresult = max(maxresult, current);
        minresult = min(minresult, current);
        return;
    }

    for(int i=0;i<4;i++) {
        if(ope[i]>0) {
            ope[i]--;
            int next = current;
            if(i==0) next += A[idx];
            else if(i==1) next -= A[idx];
            else if(i==2) next *= A[idx];
            else {
                if(next>=0) next /= A[idx];
                else next = -(-next / A[idx]);
            }

            dfs(idx+1, next);
            ope[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    cin >> ope[0] >> ope[1] >> ope[2] >> ope[3];

    dfs(1,A[0]);

    cout << maxresult << '\n' << minresult << '\n';
}