#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,int> cnt;
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        int num;
        cin >> num;
        cnt[num] += 1;
    }

    int M;
    cin >> M;
    for(int i=0;i<M;i++) {
        int num;
        cin >> num;
        if(cnt[num]>0) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}