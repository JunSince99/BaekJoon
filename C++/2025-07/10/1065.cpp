#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        if(i<100) cnt++;
        else {
            bool isHan = true;
            int cur = i;
            int diff = (cur%10) - ((cur%100)/10);
            cur /= 10;
            while(cur>=10) {
                if (diff != (cur%10) - ((cur%100)/10)) {
                    isHan = false;
                    break;
                }
                cur /= 10;
            }
            if (isHan)
                cnt++;
        }
    }

    cout << cnt;
}