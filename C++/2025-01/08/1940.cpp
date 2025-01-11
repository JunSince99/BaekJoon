#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> ing(n);
    for(int i=0;i<n;i++) {
        cin >> ing[i];
    }
    sort(ing.begin(),ing.end());

    int a=0;
    int b=n-1;
    int answer = 0;

    while(a<b) {
        if(ing[a]+ing[b] > m) {
            b--;
        } else if(ing[a] + ing[b] < m) {
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