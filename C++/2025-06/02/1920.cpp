#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int A[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> A[i];
    sort(A,A+N);
    cin >> M;
    for(int i=0;i<M;i++) {
        int cur;
        cin >> cur;
        int left = 0;
        int right = N-1;
        bool is = false;
        while(left<=right) {
            int mid = (left+right)/2;
            if(A[mid] < cur) {
                left = mid + 1;
            } else if (A[mid] > cur) {
                right = mid - 1;
            } else {
                cout << 1 << '\n';
                is = true;
                break;
            }
        }
        if(!is) cout << 0 << '\n';
    }

}