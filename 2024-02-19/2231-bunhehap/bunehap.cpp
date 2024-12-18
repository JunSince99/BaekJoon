#include <iostream>

using namespace std;

int bunesum(int a) {
    int result = 0;
    do{
        result = result + (a%10);
        a = a/10;
    }while(a!=0);
    return result;
}

int main() {
    int n;
    cin >> n;
    int result = 0;
    for(int i=n-1;i>0;i--){
        if(i+bunesum(i) == n){
            result = i;
        }
    }
    cout << result << '\n';
}