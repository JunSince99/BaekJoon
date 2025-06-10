#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int ans = INF;
int dp[100001][5][5];
vector<int> steps;

int cost(int from, int to) {
    if (from == 0) return 2;
    else if (abs(to - from) == 2) return 4;
    else if (from == to) return 1;
    else return 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        int x;
        cin >> x;
        if(x == 0) break;
        steps.push_back(x);
    }

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            dp[0][i][j] = INF;
    dp[0][0][0] = 0;

    for(int i=0;i<steps.size();i++) {
        for(int l=0;l<5;l++)
            for(int r=0;r<5;r++)
                dp[i+1][l][r] = INF;
        
        int cmd = steps[i];
        
        for(int l=0;l<5;l++) {
            for(int r=0;r<5;r++) {
                int cur = dp[i][l][r];
                if(cur == INF) continue;

                if(cmd != r)
                    dp[i+1][cmd][r] = min(dp[i+1][cmd][r], cur + cost(l,cmd));
                if(cmd != l)
                    dp[i+1][l][cmd] = min(dp[i+1][l][cmd], cur + cost(r,cmd));
            }
        }
    }

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            ans = min(ans, dp[steps.size()][i][j]);

    cout << ans;
}

// #include <iostream>
// using namespace std;

// pair<int,int> foot;
// int Power = 0;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     while(true) {
//         int cmd;
//         cin >> cmd;
//         if(cmd == 0) break;
//         int leftmove, rightmove;
//         if(foot.first == 0) leftmove = 2;
//         else if(abs(cmd-foot.first) == 2) leftmove = 4;
//         else if(cmd == foot.first) leftmove = 1;
//         else leftmove = 3;

//         if(foot.second == 0) rightmove = 2;
//         else if(abs(cmd-foot.second) == 2) rightmove = 4;
//         else if(cmd == foot.second) rightmove = 1;
//         else rightmove = 3;

//         if(leftmove < rightmove) {
//             foot.first = cmd;
//             Power += leftmove;
//         } else {
//             foot.second = cmd;
//             Power += rightmove;
//         }
//     }

//     cout << Power;
// }

//그리디로 하면 오답!! 항상 최적의 해를 찾지 못함
//반례 : 1 2 3 4 1 2 3 4 0
// (1,3) 을 밟고 있는 상황에서 4로 가려면
// (4,3), (1,4) 둘 다 똑같은 힘이 들어가지만
// 그 다음 입력이 1 이므로 (1,4)로 가서 1을 남기면
// 최적의 경우지만 그리디로는 무조건 같은 힘이 들어갈 경우
// 오른발만 움직이므로 왼발을 남겨야하는 상황이면 오답이 나옴.