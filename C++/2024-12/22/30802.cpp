#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int size[6];
    for (int i=0; i<6; i++) {
        cin >> size[i];
    }

    int T, P;
    cin >> T >> P;

    //t-shirts
    int tshirts = 0;
    for (int i=0;i<6;i++) {
        if (size[i]%T == 0) {
            tshirts += size[i]/T;
        } else {
            tshirts += size[i]/T + 1;
        }
    }
    cout << tshirts << endl;
    //pen
    cout << N/P << " " << N%P << endl;
}