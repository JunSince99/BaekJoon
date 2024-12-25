#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<string>> members(201);
    for(int i=0;i<N;i++) {
        int age;
        string name;
        cin >> age >> name;
        members[age].push_back(name);
    }
    for(int i=1;i<201;i++){
        for(string mem : members[i]) {
            cout << i << ' ' << mem << '\n';
        }
    }

    return 0;
}