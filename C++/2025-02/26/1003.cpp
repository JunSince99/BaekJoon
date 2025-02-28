#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        int N;
        int a,b;
        cin >> N;

        a=1,b=0;
        if(N == 0) 
            cout << a;
        else if(N == 1)
            cout << b;
        else {
            for(int i=2;i<=N;i++) {
                int temp = a+b;
                a = b;
                b = temp;
            }
            cout << b;
        }
        
        a=0,b=1;
        if(N == 0) 
            cout << " " << a << '\n';
        else if(N == 1)
            cout << " " << b << '\n';
        else {
            for(int i=2;i<=N;i++) {
                int temp = a+b;
                a = b;
                b = temp;
            }
            cout << " " << b << '\n';
        }
    }

    return 0;
}

// int countzero(int N, vector<int>& fibzero) {
//     if(N<fibzero.size()) {
//         return fibzero[N];
//     } else {
//         int index = fibzero.size()-1;

//     }
// }

// int countone(int N, vector<int>& fibone) {

// }