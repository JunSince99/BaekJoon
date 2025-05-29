#include <iostream>
using namespace std;

int N, S;
int cnt=0;
int nums[20];

void recur(int depth, int sum) {
    if(depth == N) {
        if(sum == S)
            cnt++;
        return;
    }
    recur(depth+1, sum);
    recur(depth+1, sum+nums[depth]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i=0;i<N;i++)
        cin >> nums[i];
    recur(0, 0);
    if (S == 0) cnt--;
    cout << cnt << '\n';
}