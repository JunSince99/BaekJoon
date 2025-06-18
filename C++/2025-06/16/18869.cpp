#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int uni[100][1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) cin >> uni[i][j];
        vector<int> v(uni[i],uni[i]+n);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()), v.end());
        for(int j=0;j<n;j++) {
            uni[i][j] = lower_bound(v.begin(),v.end(),uni[i][j]) - v.begin();
        }
    }

    int ans = 0;
    for(int i=0;i<m-1;i++) {
        for(int j=i+1;j<m;j++) {
            bool isit = true;
            for(int k=0;k<n;k++) {
                if(uni[i][k] != uni[j][k]) {
                    isit = false;
                    break;
                }
            }
            if(isit) ans++;
        }
    }
    cout << ans;
}