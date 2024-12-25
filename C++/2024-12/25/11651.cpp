#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int,int>> coor(N);
    for(int i=0;i<N;i++) {
        cin >> coor[i].second >> coor[i].first;
    }

    sort(coor.begin(),coor.end());
    for (int i=0;i<N;i++) {
        cout << coor[i].second << ' ' << coor[i].first << '\n';
    }

    return 0;
}