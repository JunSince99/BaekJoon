#include <iostream>
#include <vector>
using namespace std;

int N;
bool isPrime[4000001];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(isPrime,isPrime+N+1,true);
    isPrime[1] = false;
    for(int i=2;i<=N;i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            int temp = i+i;
            while(temp<=N) {
                isPrime[temp] = false;
                temp += i;
            }
        }
    }
    
    int ans = 0;
    
    int sum = 0;
    int left = 0;
    int right = 0;
    while(true) {
        if(sum >= N) sum -= primes[left++];
        else if(right == primes.size()) break;
        else sum += primes[right++];

        if(sum == N) ans++;
    }

    cout << ans;
}