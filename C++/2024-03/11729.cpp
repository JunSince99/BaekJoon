#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int from, int other, int to, int n){
    if (n==1) cout << from << " " << to << '\n';
    else{
        hanoi(from,to,other,n-1);
        cout << from << " " << to << '\n';
        hanoi(other,from,to,n-1);
    }
}

int main(){
    int N;
    cin >> N;
    cout << int(pow(2,N))-1 << '\n';
    hanoi(1,2,3,N);
}