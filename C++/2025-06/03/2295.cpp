#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int U[1000];
vector<int> sums;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> U[i];
    }
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        sums.push_back(U[i]+U[j]);
    
    sort(sums.begin(),sums.end());
    for(int i=N-1;i>=0;i--) {
        for(int j=0;j<N;j++) {
            if(binary_search(sums.begin(),sums.end(),U[i]-U[j])) {
                cout << U[i];
                return 0;
            }
        }
    }
}