#include <iostream>
#include <vector>

using namespace std;

int A[1025][1025];
int S[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> A[i][j];

            S[i][j] = A[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
        }
    }
    
    for(int i=0;i<m;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1] << '\n';
    }

    return 0;
}
