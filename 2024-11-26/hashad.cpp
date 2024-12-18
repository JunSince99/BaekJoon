#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = x;
    int div = 0;
    while(temp>0) {
        div += temp%10;
        temp /= 10;
    }
    return (x % div == 0);
}

int main() {
    int x = 10000;
    cout << solution(x);
}