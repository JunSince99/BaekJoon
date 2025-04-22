#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        int N;
        cin >> N;
        map<string,int> cnt;
        for (int n=0;n<N;n++) {
            string a, b;
            cin >> a >> b;
            cnt[b] += 1;
        }
        int answer = 1;
        for(auto a : cnt) {
            answer = answer * (a.second+1);
        }
        cout << answer - 1 << '\n';
    }

    return 0;
}