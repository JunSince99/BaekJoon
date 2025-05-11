#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> answer(N,vector<int>(N));
    map<int,int> maps;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int v;
            cin >> v;
            maps[i] = v;
        }
    }

    for(auto m:maps) {
        vector<vector<bool>> visited(N,vector<bool>(N));
        queue<int> q;
        
    }
}