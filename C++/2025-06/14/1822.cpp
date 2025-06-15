#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int A[500000];
int B[500000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];
    sort(A,A+n);
    sort(B,B+m);
    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(!binary_search(B,B+m,A[i])) {
            ans.push_back(A[i]);
        }
    }
    cout << ans.size() << '\n';
    for(int& a: ans) {
        cout << a << ' ';
    }
}