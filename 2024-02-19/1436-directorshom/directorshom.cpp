#include <iostream>
#include <string>

using namespace std;

bool isTripleSix(int num) {
    string temp = to_string(num);
    int cnt = 0;
    for(char a : temp){
        if(cnt<3){
            if(a=='6') cnt++;
            else cnt = 0;
        } else {
            return true;
        }
        if(cnt >= 3) return true;
    }
    return false;
}

int main() {
    int n, cnt=0;
    cin >> n;
    int start = 666;
    while(cnt<n){
        if(isTripleSix(start)) cnt++;
        start += 1;
    }
    cout << start-1 << '\n';
}