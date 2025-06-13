#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int cards[500000];

bool binaary(int C[], int n) {
    int left = 0;
    int right = N-1;
    while(left <= right) {
        int mid = (left+right) / 2;
        if(C[mid] < n) {
            left = mid + 1;
        } else if(C[mid] > n) {
            right = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> cards[i];

    sort(cards,cards+N);

    cin >> M;
    while(M--) {
        int num;
        cin >> num;
        cout << binaary(cards,num) << ' ';
    }
}