#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<long long> padoban = {1,1,1};
    for(int t=0;t<T;t++) {
        int N;
        cin >> N;

        if(N > padoban.size()) {
            for(int n = padoban.size();n<=N;n++) {
                padoban.push_back(padoban[n-3]+padoban[n-2]);
            }
        }
        cout << padoban[N-1] << '\n';
    }
}