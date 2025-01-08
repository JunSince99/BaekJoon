#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n;

    vector<int> numbers(n);
    for(int i=0;i<n;i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(),numbers.end());
    cin >> x;

    int a=0;
    int b=n-1;
    int answer = 0;
    while(a<b) {
        if(numbers[a]+numbers[b] > x) {
            b--;
        } else if(numbers[a] + numbers[b] < x) {
            a++;
        } else {
            answer++;
            a++;
            b--;
        }
    }

    cout << answer << '\n';

    return 0;
}