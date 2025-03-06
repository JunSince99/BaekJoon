#include <iostream>

using namespace std;

int N;
int paper[128][128];
int blue = 0;
int white = 0;

void cut(int sx, int sy, int n) {
    bool isfirst = true;
    int first;
    for(int i=sx;i<sx+n;i++) {
        for(int j=sy;j<sy+n;j++) {
            if(isfirst){
                first = paper[i][j];
                isfirst = false;
            } else {
                if(first != paper[i][j]){
                    cut(sx,sy,n/2);
                    cut(sx+(n/2),sy,n/2);
                    cut(sx,sy+(n/2),n/2);
                    cut(sx+(n/2),sy+(n/2),n/2);
                    return;
                }
            }
        }
    }
    if(first == 0){
        white++;
    } else {
        blue++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            cin >> paper[i][j];
        }
    }

    cut(0,0,N);

    cout << white << endl;
    cout << blue << endl;
}