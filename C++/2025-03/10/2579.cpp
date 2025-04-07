// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// struct onlyup {
//     int curlo, score, rowleft;
// };

// int main() {
//     int N;
//     cin >> N;
//     vector<int> stair(N);
//     for (int n=0;n<N;n++) {
//         cin >> stair[n];
//     }
//     int maxval = 0;
//     queue<onlyup> q;// curlocation, score, rowleft
//     q.push({-1,0,2});
//     while(!q.empty()) {
//         onlyup cur = q.front();
//         q.pop();
//         int crl = cur.curlo;
//         int sc = cur.score;
//         int rwlft = cur.rowleft;

//         if (crl == N-1) {
//             maxval = max(maxval, sc);
//             continue;
//         }

//         if (rwlft > 0 && crl+1<N) {
//             //한칸 가기
//             q.push({crl+1,sc+stair[crl+1],rwlft-1});
//         }
//         //두칸 가기
//         if(crl+2<N) {
//             q.push({crl+2,sc+stair[crl+2],1});
//         }
//     }

//     cout << maxval << '\n';
// }

//시간초과 코드 