#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int low_bnd (vector<int>& ve, int target) {
    int left=0;
    int right = ve.size();
    while(left<right) {
        int mid = (left+right) / 2;
        if(ve[mid]<target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> indx(N);
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }
    vector<int> lis;
    
    for(int i=0;i<N;i++) {
        int pos = low_bnd(lis,A[i]);
        indx[i] = pos;
        if(pos == lis.size()) {
            lis.push_back(A[i]);
        } else {
            lis[pos] = A[i];
        }
    }

    int target = lis.size();
    cout << target-- << '\n';
    for(int i=N-1;0<=i;i--) {
        if(indx[i] == target) {
            lis[target--] = A[i];
        }
    }

    for(int i=0;i<lis.size();i++) {
        cout << lis[i] << ' ';
    }
    cout << '\n';
    return 0;
}