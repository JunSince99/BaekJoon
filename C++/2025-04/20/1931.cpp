#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> hoei(N);
    for(int i=0;i<N;i++) {
        cin >> hoei[i].first >> hoei[i].second;
    }

    //second 기준으로 정렬
    sort(hoei.begin(),hoei.end(),[] (auto &a, auto &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    int end = 0;
    int cnt = 0;
    for(auto ho : hoei) {
        if (ho.first >= end) {
            end = ho.second;
            cnt++;
        }
    }

    cout << cnt << '\n';
}