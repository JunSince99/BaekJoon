#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int tri[3];
        for(int i=0;i<3;i++) {
            cin >> tri[i];
        }
        sort(tri,tri+3);
        if (tri[0]==0 && tri[1]==0 && tri[2]==0) return 0;
        else if((tri[0]*tri[0])+(tri[1]*tri[1]) == (tri[2]*tri[2])) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
}