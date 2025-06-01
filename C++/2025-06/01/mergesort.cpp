#include <iostream>
using namespace std;

int main() {
    int n,m;
    int a[20], b[20], c[20];
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    //a와 b를 병합하는 코드
    int aidx=0, bidx=0;
    for(int i=0;i<n+m;i++) {
        if(aidx>=n) {
            c[i] = b[bidx++];
            continue;
        }
        if(bidx>=m) {
            c[i] = a[aidx++];
            continue;
        }
        if(a[aidx]<b[bidx]) c[i] = a[aidx++];
        else c[i] = b[bidx++];
    }
    for(int i=0;i<n+m;i++) cout << c[i] << ' ';
}

// 5 4
// -9 1 6 8 12
//-7 7 13 15