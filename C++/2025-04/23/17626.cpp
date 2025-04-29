#include <iostream>

using namespace std;

int laglang[50001];

int main() {
    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        laglang[i] = i;

        for(int j=1;j*j<=i;j++) {
            laglang[i] = min(laglang[i], laglang[i-(j*j)]+1);
        }
    }

    cout << laglang[n] << '\n';
}