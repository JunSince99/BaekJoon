#include <iostream>
using namespace std;

int paper[2200][2200];
int cnt[3] = {0};

bool isSame(int x, int y, int z) {
    for(int i=x;i<x+z;i++)
    for(int j=y;j<y+z;j++)
        if(paper[x][y] != paper[i][j])
        return false;
    return true;
}

void recur(int x, int y, int z) {
    if(isSame(x,y,z)) {
        cnt[paper[x][y]+1]++;
        return;
    }
    int nz = z / 3;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        recur(x + nz*i, y + nz*j, nz);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cin >> paper[i][j];
    
    recur(0,0,n);
    for(int i=0;i<3;i++)
        cout << cnt[i] << '\n';
}