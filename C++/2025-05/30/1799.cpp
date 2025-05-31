#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans[2];
vector<pair<int,int>> canput[2];
bool dia1[20], dia2[20];

void recur(int depth, int cnt, int color) {
    if(depth == canput[color].size()) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    //놓을 수 있는지 확인 후 놓기
    int x = canput[color][depth].first;
    int y = canput[color][depth].second;
    if(!dia1[x+y] && !dia2[x-y+N-1]) {
        dia1[x+y] = true;
        dia2[x-y+N-1] = true;
        recur(depth+1,cnt+1,color);
        dia1[x+y] = false;
        dia2[x-y+N-1] = false;
    }
    //안놓고 지나가기기
    recur(depth+1,cnt,color);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int cur;
            cin >> cur;
            if(cur==1) {
                if((i+j)%2==0)
                    canput[0].push_back({i,j});
                else
                    canput[1].push_back({i,j});
            }
        }
    }

    recur(0,0,0);
    recur(0,0,1);
    cout << ans[0]+ans[1];
}