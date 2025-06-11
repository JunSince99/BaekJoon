#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long ans;
int N,K;
priority_queue<int> pq;
pair<int,int> jewel[300001];
int bags[300001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
        cin >> jewel[i].first >> jewel[i].second;
    for(int i=0;i<K;i++) cin >> bags[i];
    sort(jewel,jewel+N);
    sort(bags,bags+K);
    
    int j=0;
    for(int i=0;i<K;i++) {
        while(j<N && jewel[j].first <= bags[i]) {
            pq.push(jewel[j++].second);
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}