#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int remembered[10] = {1,1,1,1,1,1,1,1,1,1};
    int answer = 10;
    cin >> N;

    while(N--) {
        if (N == 0) {
            cout << answer % 10007;
            return 0;
        }
        int temp[10] = {0,0,0,0,0,0,0,0,0,0};
        for(int i=0;i<10;i++) {
            temp[i] = answer % 10007;
            answer -= remembered[i];
        }

        for(int i=0;i<10;i++) {
            remembered[i] = temp[i];
            answer += remembered[i] % 10007; 
        }
    }
}