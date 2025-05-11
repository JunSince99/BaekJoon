#include <iostream>

using namespace std;

int samemul(int a, int b) {
    int x=a,y=b;
    while(x != y) {
        if(x<y) {
            x += a;
        } else {
            y += b;
        }
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int answer = -1;
        int lcm = samemul(M, N);

        for (int k = x; k <= lcm; k += M) {
            if ((k - y) % N == 0) {
                answer = k;
                break;
            }
        }

        cout << answer << '\n';
    } 

    return 0;
}