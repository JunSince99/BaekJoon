#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int mincost=1e9;

void dfs(int cost, int house, int lastcol,vector<vector<int>>& street) {
    if(house == N) {
        mincost = min(mincost, cost);
        return;
    }
    for(int i=0;i<3;i++) {
        if(i != lastcol) {
            dfs(cost+street[house][i], house+1,i,street);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    vector<vector<int>> street(N,vector<int>(3));

    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            cin >> street[i][j];
        }
    }
    dfs(0,0,-1,street);
    cout << mincost << '\n';
    return 0;
}