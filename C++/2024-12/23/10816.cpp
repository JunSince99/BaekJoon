#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    unordered_map<int,int> cards;
    for (int i=0;i<N;i++) {
        int card;
        cin >> card;
        if(cards.count(card)) {
            cards[card] += 1;
        } else {
            cards[card] = 1;
        }
    }

    int M;
    cin >> M;

    for (int i=0; i<M;i++) {
        int num;
        cin >> num;
        if(cards.count(num)) {
            cout << cards[num] << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';

    return 0;
}