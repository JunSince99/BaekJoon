#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> apt(15,vector<int>(14));
    apt[0] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=1;i<15;i++) {
        for(int j=0;j<14;j++) {
            int num = 0;
            for(int k=0;k<=j;k++) {
                num += apt[i-1][k];
            }
            apt[i][j] = num;
        }
    }
    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        int k,n;
        cin >> k >> n;
        cout << apt[k][n-1] << '\n';
    }
}