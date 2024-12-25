#include <iostream>

using namespace std;

void FiBuzz(int num) {
    if (num%3==0 && num%5==0) {
        cout << "FizzBuzz" << endl;
    } else if(num%3==0) {
        cout << "Fizz" << endl;
    } else if (num%5==0) {
        cout << "Buzz" << endl;
    } else {
        cout << num << endl;
    }
}

int main() {
    for(int i=3;i>0;i--) {
        string S;
        cin >> S;
        try {
            int a = stoi(S);
            a += i;
            FiBuzz(a);
            return 0;
        } catch (exception&) {
            continue;
        }
    }
}