#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M;
    cin >> M;

    unordered_map<int,int> jip;
    for(int i=0;i<M;i++) {
        string cmd;
        cin >> cmd;

        if(cmd == "add") {
            int x;
            cin >> x;
            jip[x] = 1;
        } else if(cmd == "remove") {
            int x;
            cin >> x;
            if(jip[x] == 1) {
                jip[x] = 0;
            }
        } else if(cmd == "check") {
            int x;
            cin >> x;
            cout << jip[x] << '\n';
        } else if(cmd == "toggle") {
            int x;
            cin >> x;
            if(jip[x] == 1) {
                jip[x] = 0;
            } else if(jip[x] == 0) {
                jip[x] = 1;
            }
        } else if(cmd == "all") {
            jip = {{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{14,1},{15,1},{16,1},{17,1},{18,1},{19,1},{20,1}};
        } else if(cmd == "empty") {
            jip = {};
        }
    }
}