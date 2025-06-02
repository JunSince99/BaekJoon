#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    if(a.length() != b.length()) return a.length() < b.length();

    int sumA = 0;
    for(char c:a) {
        if (isdigit(c)) sumA += c - '0';
    }
    int sumB = 0;
    for(char c:b) {
        if (isdigit(c)) sumB += c - '0';
    }
    if(sumA != sumB) return sumA < sumB;

    return a < b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<string> A(N);
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    sort(A.begin(),A.end(),cmp);

    for(int i=0;i<N;i++) {
        cout << A[i] << '\n';
    }
}