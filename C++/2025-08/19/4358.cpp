#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

map<string, float> store;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string line;

    float total = 0;

    while(getline(cin, line)) {
        if(!line.empty()) {
            store[line] += 1;
            total++;
        }
    }

    for(auto& a : store) {
        cout << a.first << ' ' << fixed << setprecision(4) << (a.second/total)*100 << '\n';
    }
}