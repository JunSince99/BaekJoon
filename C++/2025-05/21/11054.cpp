#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> dpinc(N,1);
    vector<int> dpdec(N,1);
    int mdp = 1;

    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(A[j]<A[i]) {
                dpinc[i] = max(dpinc[i], dpinc[j]+1);
            }
        }
        mdp = max(mdp, dpinc[i]);
    }

    for(int i=N-2;0<=i;i--) {
        for(int j=N-1;i<j;j--) {
            if(A[j]<A[i]) {
                dpdec[i] = max(dpdec[i],dpdec[j]+1);
            }
        }
        mdp = max(mdp, dpinc[i]+dpdec[i]-1);
    }

    cout << mdp << '\n';
    return 0;
}