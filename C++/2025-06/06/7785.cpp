#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, bool, greater<string>> isInCom;
    while(n--) {
        string name, EorO;
        cin >> name >> EorO;

        if(EorO == "enter") {
            isInCom[name] = true;
        } else if(EorO == "leave") {
            isInCom[name] = false;
        }
    }

    for(auto& is:isInCom) {
        if(is.second == false) continue;
        cout << is.first << '\n';
    }
}