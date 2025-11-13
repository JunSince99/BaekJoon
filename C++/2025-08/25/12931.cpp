#include <iostream>

using namespace std;

int cnt;
int N;
int B[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++) cin >> B[i];

    while(true) {
        bool isend = true;
        for(int i=0;i<N;i++) {
            if(B[i] == 0) continue;
            if(B[i] % 2 != 0) {
                B[i]--;
                cnt++;
            }
            B[i] /= 2;
            if(B[i] != 0) isend = false;
        }
        if(isend) break;
        cnt++;
    }

    cout << cnt;
}