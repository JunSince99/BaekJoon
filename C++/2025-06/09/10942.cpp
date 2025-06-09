#include <iostream>
using namespace std;

int N,M;
int nums[2000];
bool dp[2000][2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> nums[i];
    }

    for(int i=0;i<N;i++) {
        dp[i][i] = true;
        int left = i-1;
        int right = i+1;
        while(left>=0 && right<N) {
            if(dp[left+1][right-1]&& nums[left] == nums[right]) {
                dp[left--][right++] = true;
            } else break;
        }
        if(i == N-1) continue;
        if(nums[i] == nums[i+1]) {
            dp[i][i+1] = true;
            left = i-1;
            right = i+2;
            while(left>=0 && right<N) {
                if(dp[left+1][right-1]&& nums[left] == nums[right]) {
                    dp[left--][right++] = true;
                } else break;
            }
        }
    }
    cin >> M;
    while(M--) {
        int s,e;
        cin >> s >> e;
        cout << dp[s-1][e-1] << '\n';
    }
}

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N;
//     for(int i=0;i<N;i++) cin >> nums[i];
//     cin >> M;
//     while(M--) {
//         bool ispallin = true;
//         int s,e;
//         cin >> s >> e;
//         s--;e--;
//         while(s<e) {
//             if (nums[s] != nums[e]) {
//                 ispallin = false;
//                 break;
//             }
//             s++;
//             e--;
//         }
//         if(ispallin) cout << 1 << '\n';
//         else cout << 0 << '\n';
//     }
// }

//처음 생각난 풀이법들
// 1. 투포인터 -> 시간 초과
// 2. reverse로 뒤집고 똑같은지 보기

// 투포인터 풀이 이후에 든 생각
// reverse도 사실상 똑같은 방식이라 시간 초과일 것 같고
// dp로 풀어볼까 싶음

//예ㅖㅖㅖㅖㅖㅖㅖㅖㅖㅖ dp로 풀린다ㅏㅏㅏㅏㅏㅏㅏㅏ
//나 혼자 힘으로 풀었다ㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏ
//ㅇㄴ래ㅑㅗㄷ재ㅗ래쟈내어;ㅐ랴ㅓㅇ야호야호야호야호야호