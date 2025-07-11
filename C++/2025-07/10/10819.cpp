#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt;

;void permu(vector<int> arr, int start) {
    if (start == arr.size()) {
        return;
    }
    int temp=0;
    for(int i=0;i<arr.size()-1;i++) {
        temp += abs(arr[i]-arr[i+1]);
    }
    cnt = max(cnt, temp);
    for (int i = start;i<arr.size();i++) {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;

        permu(arr, start+1);

        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    
    permu(A, 0);
    cout << cnt;
}