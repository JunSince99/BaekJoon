#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    string str;
    cin >> N >> M;
    cin >> str;

    string keystr = "I";
    for(int i=0;i<N;i++) {
        keystr = keystr + "OI";
    }

    int right = keystr.size();
    int cnt=0;

    for(int left=0;left<=M-right;left++) {
        if (str.substr(left,right) == keystr) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}