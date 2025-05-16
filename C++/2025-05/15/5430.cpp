#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        string p,list;
        int n;
        cin >> p >> n >> list;

        deque<int> dq;
        string num;
        for(char c:list) {
            if(isdigit(c)) {
                num += c;
            } else if(!num.empty()) {
                dq.push_back(stoi(num));
                num.clear();
            }
        }

        bool isrevert = false;
        bool iserror = false;

        for(char c:p) {
            if(c=='R') {
                isrevert = !isrevert;
            } else if(c=='D') {
                if(isrevert && dq.size() != 0) {
                    dq.pop_back();
                } else if(!isrevert && dq.size() != 0) {
                    dq.pop_front();
                } else {
                    cout << "error" << '\n';
                    iserror = true;
                    break;
                }
            }
        }

        if(!iserror) {
            cout << '[';
            if(dq.empty()) cout << ']' <<  '\n';
            while(!dq.empty()) {
                if(isrevert) {
                    int cur = dq.back();
                    dq.pop_back();
                    cout << cur;
                    if(dq.empty()) cout << ']' << '\n';
                    else cout << ',';
                } else {
                    int cur = dq.front();
                    dq.pop_front();
                    cout << cur;
                    if(dq.empty()) cout << ']' << '\n';
                    else cout << ',';
                }
            }
        }
    }

    return 0;
}