#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> classes(N);
    for(int i=0;i<N;i++) {
        cin >> classes[i].first >> classes[i].second;
    }
    sort(classes.begin(),classes.end());

    priority_queue<int, vector<int>, greater<int>> mhp;

    for (pair cls : classes) {
        int start = cls.first;
        int end = cls.second;

        if (!mhp.empty() && mhp.top() <= start) {
            mhp.pop();
        }

        mhp.push(end);
    } 

    cout << mhp.size() << endl;

    return 0;
}