#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> cards;
    int answer = 0;

    for(int i=0;i<N;i++) {
        int c;
        cin >> c;
        cards.push(c);
    }

    while(cards.size() != 1) {
        int addy = 0;
        addy += cards.top();
        cards.pop();
        addy += cards.top();
        cards.pop();

        cards.push(addy);
        answer += addy;
    }

    cout << answer << endl;

    return 0;
}