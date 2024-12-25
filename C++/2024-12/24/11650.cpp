#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<set<int>> coor(200002);

    for(int i=0;i<N;i++) {
        int x,y;
        cin >> x >> y;
        coor[x+100000].insert(y);
    }
    cout << '\n';
    for(int i=0;i<200002;i++) {
        for(const int &dy : coor[i]) {
            cout << i - 100000 << ' ' << dy << '\n';
        }
    }

    return 0;
}