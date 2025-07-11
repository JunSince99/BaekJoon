#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
int sum[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sum[0] = arr[0];
    int result = sum[0];

    for(int i=1;i<n;i++) {
        sum[i] = max(arr[i], sum[i-1]+arr[i]);
        result = max(result, sum[i]);
    }

    cout << result;
}