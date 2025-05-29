#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L,C;
vector<char> Al;
char answer[15];

void recur(int depth, int cur) {
    if(depth == L) {
        int cnt = 0;
        for(int i=0;i<L;i++) {
            if(answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u') {
                cnt++;
            }
        }
        if (cnt<1 || cnt > L-2) return;
        for(int i=0;i<L;i++) {
            cout << answer[i];
        }
        cout << '\n';
        return;
    }
    for(int i=cur;i<C;i++) {
        answer[depth] = Al[i];
        recur(depth+1, i+1);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    for(int i=0;i<C;i++) {
        char t;
        cin >> t;
        Al.push_back(t);
    }
    sort(Al.begin(),Al.end());
    recur(0,0);
}