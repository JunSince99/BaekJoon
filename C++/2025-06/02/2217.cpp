#include <iostream>
#include <algorithm>
using namespace std;

int N;
int rope[100000];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++)
        cin >> rope[i];
    sort(rope, rope+N);

    int minRope = 1e9;
    int maxWeight = 0;
    for(int i=N-1;i>=0;i--) {
        minRope = min(minRope, rope[i]);
        maxWeight = max(maxWeight, (minRope * (N-i)));
    }
    cout << maxWeight;
}