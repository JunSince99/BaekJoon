#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t=0;t<T;t++) {
        int H,W,N;
        cin >> H >> W >> N;
        if(N%H==0) {
            cout << (H*100) + N/H << endl;
        } else {
            cout << (N%H)*100 + N/H + 1 << endl;
        }
    }
}