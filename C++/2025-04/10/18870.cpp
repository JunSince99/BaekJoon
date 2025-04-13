#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N);
    vector<int> Xa(N);
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        X[i] = num;
        Xa[i] = num;
    }

    sort(Xa.begin(),Xa.end());
    map<int, int> counter;
    int temp = 0;
    for(int xa:Xa) {
        if(!counter.count(xa)) {
            counter[xa] = temp++;
        }
    }

    for(int i=0;i<N;i++) {
        cout << counter[X[i]] << ' ';
    }

    cout << '\n';

    return 0;
}