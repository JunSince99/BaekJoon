// #include <iostream>
// using namespace std;

// long long n;
// long long a, b;
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;

//     a = 0, b = 1;
//     for(long long i=2;i<=n;i++) {
//         long long nxt = (a+b) % 1000000007;
//         a = b;
//         b = nxt;
//     }

//     cout << b;
// }

// O(n)인 알고리즘으로는 입력이 10^18인 문제를 풀 수 없다..
// O(log n)인 알고리즘이면 대략 60까지 줄어드니 넉넉하게 풀 수 있게 된다!
// log n을 위해서는 행렬을 이용해야 한다.

#include <iostream>
#include <vector>
using namespace std;

const int TAR = 1000000007;
long long n;

vector<long long> fibo(long long num) {
    if(num==0) return {0,0,0,0};
    if(num==1) return {1,1,1,0};

    vector<long long> temp = fibo(num/2);
    long long first = ((temp[0]*temp[0])%TAR+(temp[1]*temp[2])%TAR)%TAR;
    long long second = ((temp[0]*temp[1])%TAR + (temp[1]*temp[3])%TAR)%TAR;
    long long third = ((temp[2]*temp[0])%TAR + (temp[3]*temp[2])%TAR)%TAR;
    long long fourth = ((temp[2]*temp[1])%TAR+(temp[3]*temp[3])%TAR)%TAR;
    if(num%2==0) return {first, second, third, fourth};
    else return {(first+second)%TAR, first, (third+fourth)%TAR, third};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n==1) {
        cout << 1;
        return 0;
    }
    vector<long long> answer = fibo(n-1);
    cout << answer[0] << '\n';
}