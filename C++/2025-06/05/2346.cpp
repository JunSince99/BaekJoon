#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    deque<pair<int,int>> dq;
    for(int i=0;i<N;i++) {
        int num;
        cin >> num;
        dq.push_back({num,i+1});
    }
    vector<int> ans;
    while(!dq.empty()) {
        pair<int,int> cur = dq.front();
        dq.pop_front();
        ans.push_back(cur.second);
        if(dq.empty()) break;
        if(cur.first>0) {
            for(int i=0;i<cur.first-1;i++) {
                pair<int,int> temp = dq.front();
                dq.push_back(temp);
                dq.pop_front();
            }
        } else {
            for(int i=0;i<-cur.first;i++) {
                pair<int,int> temp = dq.back();
                dq.push_front(temp);
                dq.pop_back();
            }
        }
    }
    for(int a:ans) {
        cout << a << ' ';
    }
}