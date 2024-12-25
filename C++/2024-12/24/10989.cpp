#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt[10001] = {0};

    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        int num;
        cin >> num;

        cnt[num] += 1;
    }

    for(int i=0;i<10001;i++) {
        for(int j=0;j<cnt[i];j++) {
            cout << i << '\n';
        }
    }

    return 0;
}