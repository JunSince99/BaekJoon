#include <iostream>
using namespace std;

string A;
int t=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A;

    for(char& c : A) {
        if(c>= 'A' && c<= 'C') t += 3;
        else if(c >= 'D' && c<='F') t += 4;
        else if(c>='G'&&c<='I') t+=5;
        else if(c>='J'&&c<='L') t+=6;
        else if(c>='M'&&c<='O') t+=7;
        else if(c>='P'&&c<='S') t+=8;
        else if(c>='T'&&c<='V') t+=9;
        else if(c>='W'&&c<='Z') t+=10;
    }

    cout << t;
}