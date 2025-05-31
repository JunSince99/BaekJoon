#include <iostream>
using namespace std;

long long aabs(long long a) {
    if (a<0) return -a;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;

    long long lx=0, ly=0;
    long long fx,fy,x,y;
    cin >> fx >> fy;
    x = fx;
    y = fy;
    for(int i=1;i<N;i++) {
        long long nx, ny;
        cin >> nx >> ny;
        lx += x * ny;
        ly += y * nx;
        x = nx;
        y = ny;
    }
    lx += x * fy;
    ly += y * fx;
    double answer = aabs(lx-ly) / 2.0; 
    cout << fixed;
    cout.precision(1);
    cout << answer << '\n';
}