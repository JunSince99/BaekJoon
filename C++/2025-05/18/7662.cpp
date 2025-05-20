#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int k;
        cin >> k;

        multiset<int> ms;

        while(k--) {
            char cmd;
            int n;
            cin >> cmd >> n;

            if (cmd == 'I') {
                ms.insert(n);
            } else if (cmd == 'D' && !ms.empty()) {
                if (n == 1) {
                    ms.erase(prev(ms.end()));
                } else if (n == -1) {
                    ms.erase(ms.begin());
                }
            }
        }

        if(ms.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}