#include <iostream>
#include <unordered_map>
using namespace std;

string find(string a, unordered_map<string, pair<string,int>>& um) {
    if(um.find(a) == um.end()) {
        um[a] = {"", 1};
        return a;
    }
    if (um[a].first == "") return a;
    um[a].first = find(um[a].first, um);
    return um[a].first;
}

void uni(string a, string b, unordered_map<string, pair<string,int>>& um) {
    a = find(a,um);
    b = find(b,um);
    if(a != b) {
        um[a].second = um[a].second + um[b].second;
        um[b].first = a;
    }
    cout << um[a].second << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        unordered_map<string, pair<string,int>> um;
        int F;
        cin >> F;
        while(F--) {
            string A, B;
            cin >> A >> B;

            uni(A,B,um);
        }
    }
}