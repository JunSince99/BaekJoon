#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin >> N >> K;

    vector<int> coins(N);
    for(int i=0;i<N;i++) {
        cin >> coins[i];
    }

    int count = 0;
    int cur_index = N-1;
    while(K>0) {
        while(coins[cur_index]>K) {
            cur_index--;
        }
        K -= coins[cur_index];
        count++;
    }

    cout << count << endl;
}