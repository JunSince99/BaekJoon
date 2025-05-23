#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int ans=2e9;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

void dfs(int idx, vector<int> &selected) {
    if(selected.size() == m) {
        int sum = 0;
        for(int i=0;i<houses.size();i++) {
            int acloset = 2e9;
            for(int j=0;j<selected.size();j++) {
                acloset = min(acloset, abs(houses[i].first-chickens[selected[j]].first)+abs(houses[i].second-chickens[selected[j]].second));
            }
            sum += acloset;
        }
        ans = min(ans, sum);
        return;
    }

    if(idx < chickens.size()) {
        selected.push_back(idx);
        dfs(idx+1, selected);
        selected.pop_back();

        dfs(idx + 1, selected);
    }
}

int main() {
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int temp;
            cin >> temp;

            if(temp == 1) houses.push_back({i,j});
            else if(temp == 2) chickens.push_back({i,j});
        }
    }

    vector<int> select;
    dfs(0,select);

    cout << ans << '\n';
    return 0;
}