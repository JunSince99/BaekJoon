#include <iostream>
#include <vector>

using namespace std;

int low_bnd(vector<int>& ve, int target) {
    int left = 0;
    int right = ve.size();
    while(left<right) {
        int mid = (left+right) / 2;
        if(ve[mid] < target) {
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
    vector<int> lis;

    vector<int> answer;

    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    for(int i=0;i<N;i++) {
        int pos = low_bnd(lis, A[i]);
        if(pos == lis.size()) {
            lis.push_back(A[i]);
        } else {
            if(pos == 0 && lis[pos] != A[i]) {
                lis = {A[i]};
            } else if (pos == lis.size()-1) {
                lis.pop_back();
                lis.push_back(A[i]);
            }
        }
    }

    cout << lis.size() << '\n';
    for(int i : lis) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}