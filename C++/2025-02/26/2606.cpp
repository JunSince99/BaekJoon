#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int computer, link;
    cin >> computer >> link;

    vector<bool> visited(computer);
    map<int,vector<int>> network;
    int count = 0;
    for (int t = 0; t < link; t++) {
        int from, to;
        cin >> from >> to;
        network[from].push_back(to);
        network[to].push_back(from);
    }
    
    queue<int> q;
    visited[0] = true;
    for(int to : network[1]) {
        q.push(to);
        visited[to-1] = true;
        count++;
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int to : network[cur]) {
            if(!visited[to-1]) {
                q.push(to);
                visited[to-1] = true;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}