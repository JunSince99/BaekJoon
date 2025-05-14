#include <iostream>

using namespace std;

int main() {
    int n,m;
    string IOI;
    cin >> n >> m;
    cin >> IOI;

    int count = 0;
    int result = 0;
    int i = 1;

    while(i<m-1) {
        if(IOI[i-1] == 'I' && IOI[i] == 'O' && IOI[i+1] == 'I') {
            count++;

            if(count == n) {
                result++;
                count--;
            }
            i += 2;
        } else {
            count = 0;
            i++;
        }
    }

    cout << result << '\n';
}