#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> people(N);
    for(int i=0;i<N;i++) {
        cin >> people[i];
    }

    sort(people.begin(),people.end());

    int answer = 0;
    for(int i=0;i<N;i++) {
        answer += people[i] * (N-i);
    }

    cout << answer << endl;

    return 0;
}