#include <iostream>
using namespace std;

int n;
string video[64];
string answer = "";

bool isSame(int x, int y, int z) {
    for(int i=x;i<x+z;i++)
    for(int j=y;j<y+z;j++)
        if(video[x][y] != video[i][j])
        return false;
    return true;
}

void recur(int x, int y, int z) {
    if(isSame(x,y,z)) {
        answer += video[x][y];
        return;
    }
    int nz = z / 2;
    answer += "(";
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
        recur(x+nz*i, y+nz*j, nz);
    answer += ")";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> video[i];
    recur(0,0,n);
    cout << answer << '\n';
}