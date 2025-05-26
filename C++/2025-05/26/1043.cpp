#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int knower;
    cin >> knower;
    unordered_map<int, bool> um;
    while(knower--) {
        int p;
        cin >> p;
        um[p] = true;
    }
    vector<vector<int>> parties(m,vector<int>);
    for(int i=0;i<M;i++) {
        int pp;
        cin >> pp;
        while(pp--) {
            int p;
            cin >> p;
            parties[i].push_back(p);
        }
    }

    
}