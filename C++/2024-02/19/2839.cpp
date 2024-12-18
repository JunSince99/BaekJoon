#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result = (n / 3)+1;
    for(int i = result; i>=0;i--){
        for(int j = result; j>=0;j--){
            if((i*3)+(j*5)==n && i+j<=result){
                result = i+j;
            }
        }
    }
    if(result == (n / 3)+1)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}

