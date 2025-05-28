#include <iostream>
using namespace std;

void hanoi(int a, int b, int n) {
    //n-1이 a에서 6-a-b로 가기
    //n번 원판 이동 출력
    //n-1이 6-a-b에서 b로 가기
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a,6-a-b,n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b,b,n-1);
}

int main() {
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    hanoi(1,3,n);
    return 0;
}