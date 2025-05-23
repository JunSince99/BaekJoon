#include <iostream>
#include <algorithm>

using namespace std;

struct last{
    int x;
    int y;
    int z;
};

int main() {
    int N;
    cin >> N;

    last minlst;
    last maxlst;
    int x,y,z;
    cin >> x >> y >> z;
    minlst = {x,y,z};
    maxlst = {x,y,z};
    for(int i=1;i<N;i++) {
        int cx, cy, cz;
        int tx, ty, tz;
        cin >> cx >> cy >> cz;
        
        tx = min(minlst.x,minlst.y) + cx;
        ty = min({minlst.x,minlst.y,minlst.z}) + cy;
        tz = min(minlst.y,minlst.z) + cz;
        minlst = {tx,ty,tz};

        tx = max(maxlst.x,maxlst.y) + cx;
        ty = max({maxlst.x,maxlst.y,maxlst.z}) + cy;
        tz = max(maxlst.y,maxlst.z) + cz;
        maxlst = {tx,ty,tz};
    }

    cout << max({maxlst.x,maxlst.y,maxlst.z}) << ' ' << min({minlst.x,minlst.y,minlst.z}) << '\n';
}