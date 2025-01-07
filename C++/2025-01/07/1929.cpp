#include <iostream>
#include <cmath>

using namespace std;

bool isSosu(int num) {
    if(num==1) return false;
    else if(num == 2) return true;
    else {
        for(int i=2;i<=sqrt(num);i++) {
            if (num%i==0) return false;
        }
        return true;
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    for (int i=M;i<=N;i++) {
        if(isSosu(i)) {
            cout << i << '\n';
        }
    }
}