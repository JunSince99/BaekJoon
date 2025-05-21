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
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    vector<int> answer;
    for(int i=0;i<N;i++) {
        int pos = low_bnd(answer, A[i]);
        if (pos==answer.size()) {
            answer.push_back(A[i]);
        } else {
            answer[pos] = A[i];
        }
    }

    cout << answer.size() << '\n';
    return 0;
}