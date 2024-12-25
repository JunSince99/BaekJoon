#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n;
    cin >> n;

    set<int> rray;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        rray.insert(num);
    }

    for(const int &i:rray) {
        cout << i << endl;
    }

    return 0;
}

//ㅁㅊ;; 세트로 하면 시간초과 나네 ㄷ