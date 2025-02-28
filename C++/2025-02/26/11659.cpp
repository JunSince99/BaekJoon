#include <iostream>
#include <vector>

using namespace std;

int main() { // 누적합을 이용한 개선된 알고리즘
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> arr(N+1, 0);
    for(int n=0;n<N;n++) {
        int a;
        cin >> a;
        arr[n+1] = arr[n] + a;
    }

    for(int m=0;m<M;m++) {
        int i,j;
        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << "\n";
    }

    return 0;
}
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int N, M;
//     cin >> N >> M;
//     vector<int> array(N);
//     int total = 0;
//     for(int n=0;n<N;n++) {
//         cin >> array[n];
//         total += array[n];
//     }

//     for(int m=0;m<M;m++) {
//         int i,j;
//         cin >> i >> j;
//         i--;j--;
//         int sum = 0;
//         if ((j-i)<=(N/2)) {
//             for(int index = i; index <= j; index++) {
//                 sum += array[index];
//             }
//             cout << sum << '\n';
//         } else {
//             for (int index = 0; index < i; index++) {
//                 sum += array[index];
//             }

//             for (int index = j + 1; index < N; index++) {
//                 sum += array[index];
//             }
//             cout << total - sum << '\n';
//         }
//     }
//     return 0;
// }