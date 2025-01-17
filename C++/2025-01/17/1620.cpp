#include <iostream>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    cin >> N >> M;

    unordered_map<int, string> numname;
    unordered_map<string, int> namenum;
    for(int i=1;i<=N;i++) {
        string name;
        cin >> name;
        numname[i] = name;
        namenum[name] = i;
    }
    for(int i=0;i<M;i++) {
        string q;
        cin >> q;
        if(all_of(q.begin(),q.end(), ::isdigit)) {
            cout << numname[stoi(q)] << '\n';
        } else {
            cout << namenum[q] << '\n';
        }
    }

    return 0;
}