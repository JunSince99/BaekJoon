#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,ans;
int board[20][20];

void recur(int idx, int B[20][20]) {
    if(idx == 5) {
        int cnt = 0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cnt = max(cnt, B[i][j]);
        ans = max(ans, cnt);
        return;
    }

    int temp[20][20] = {0};
    //위로 이동
    for(int j=0;j<N;j++) {
        queue<int> q;

        for(int i=0;i<N;i++)
            if(B[i][j] != 0) q.push(B[i][j]);
        int index = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if(!q.empty() && cur == q.front()) {
                temp[index++][j] = cur*2;
                q.pop();
            } else {
                temp[index++][j] = cur;
            }
        }
    }
    recur(idx+1, temp);

    //아래로 이동
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        temp[i][j] = 0;
    for(int j=0;j<N;j++) {
        queue<int> q;

        for(int i=N-1;i>=0;i--)
            if(B[i][j] != 0) q.push(B[i][j]);
        int index = N-1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if(!q.empty() && cur == q.front()) {
                temp[index--][j] = cur*2;
                q.pop();
            } else {
                temp[index--][j] = cur;
            }
        }
    }
    recur(idx+1, temp);

    //왼쪽으로 이동
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        temp[i][j] = 0;
    for(int i=0;i<N;i++) {
        queue<int> q;

        for(int j=0;j<N;j++)
            if(B[i][j] != 0) q.push(B[i][j]);
        int index = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if(!q.empty() && cur == q.front()) {
                temp[i][index++] = cur*2;
                q.pop();
            } else {
                temp[i][index++] = cur;
            }
        }
    }
    recur(idx+1, temp);

    //오른쪽으로 이동
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        temp[i][j] = 0;
    for(int i=0;i<N;i++) {
        queue<int> q;

        for(int j=N-1;j>=0;j--)
            if(B[i][j] != 0) q.push(B[i][j]);
        int index = N-1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            if(!q.empty() && cur == q.front()) {
                temp[i][index--] = cur*2;
                q.pop();
            } else {
                temp[i][index--] = cur;
            }
        }
    }
    recur(idx+1, temp);
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> board[i][j];

    recur(0,board);
    cout << ans << '\n';
}