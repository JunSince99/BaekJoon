#include <iostream>

using namespace std;
int year;

int isLeapyear(int a) {
    if((a%4==0 && a%100 != 0) || a%400==0){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    cin >> year;
    cout << isLeapyear(year) << '\n';
}