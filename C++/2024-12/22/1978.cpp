#include <iostream>

using namespace std;

bool isSosu(int num) {
    if (num == 1) return false;
    else if (num == 2) return true;
    else {
        for(int i=2;i*i<=num;i++) {
            if (num%i==0) return false;
        }
        return true;
    }
}

int main() {
    int N;
    int answer = 0;
    cin >> N;

    for (int i=0;i<N;i++) {
        int num;
        cin >> num;
        if(isSosu(num)) answer++;
    }
    cout << answer << endl;

    return 0;
}