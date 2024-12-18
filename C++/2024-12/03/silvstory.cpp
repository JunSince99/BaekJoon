// #include <iostream>
// #include <cmath>

// using namespace std;

// int main() {
//     int testcase;
//     cin >> testcase;

//     for(int t = 0; t<testcase; t++) {
//         long long N;
//         cin >> N;
        
//         long long total_exp = N * (N + 1) / 2;

//         long long near = sqrt(total_exp);
//         if ((near*(near+1)) <= total_exp) cout << near+1 << endl;
//         else cout << near << endl;
//     }
// }

// #include <iostream>
// #include <cmath>
// #include <cstdint>

// using namespace std;

// int main() {
//     for(long long N = 1; N<=1000000000; N++) {
//         long long total_exp = N * (N + 1) / 2;
//         long long a;
//         long long b;
//         long long near = sqrt(total_exp);
//         if ((near*(near+1)) <= total_exp) a = near+1;
//         else a = near;

//         b = (1 + sqrt(4*total_exp+1))/2;

//         if(a!=b) {

//             cout << a << " " << b << " " << N << endl;
//         }
//     }
// }
