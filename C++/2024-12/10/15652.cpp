// #include <iostream>
// #include <vector>

// using namespace std;

// void printVector(vector<int> vec) {
//     for (int a : vec) {
//         cout << a << ' ';
//     }
//     cout << endl;

//     return;
// }

// int main() {
//     int N, M;
//     cin >> N >> M;

//     vector<int> cur;
//     vector<int> end;
    
//     for (int i=0;i<M;i++) {
//         cur.push_back(1);
//         end.push_back(N);
//     }
//     while(cur != end) {
//         for (int a : cur) {
//             cout << a << ' ';
//         }
//         cout << endl;
//         if (cur[M-1] != N) {
//             cur[M-1] += 1;
//         } else {
//             for(int i = M-2;i>=0;i--) {
//                 if(cur[i]!=N) {
//                     cur[i] += 1;
//                     int num = cur[i];
//                     for (int j=i+1;j<M;j++) {
//                         cur[j] = num;
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     for (int a : cur) {
//         cout << a << ' ';
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> suyul;

void btr(int num) {
    if (suyul.size() == M) {
        for (int i=0; i<M;i++) {
            cout << suyul[i] << ' ';
        }
        cout << endl;
    } else {
        for (int i=num;i<=N;i++) {
            suyul.push_back(i);
            btr(i);
            suyul.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    btr(1);
    return 0;
}

// #include <iostream>

// using namespace std;

// int n,m;
// int arr[9];

// void btr(int num, int cnt) {
//     if(cnt==m){
//         for(int i=0;i<m;i++){
//             cout << arr[i] << " ";
//         }
//         cout << '\n';
//     } else {
//         for(int i=num;i<=n;i++){
//             arr[cnt] = i;
//             btr(i, cnt+1);
//         }
//     }
// }

// int main(){
//     cin >> n >> m;
//     btr(1,0);
// }