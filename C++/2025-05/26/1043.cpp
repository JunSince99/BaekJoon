#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int people[51];

int find(int x) {
    if(people[x] == x) return x;
    return people[x] = find(people[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) people[b] = a;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i=1;i<=N;i++) people[i] = i;

    int truthCount;
    cin >> truthCount;
    vector<int> truthPeople;
    for (int i=0; i<truthCount; i++) {
        int t;
        cin >> t;
        truthPeople.push_back(t);
    }

    vector<vector<int>> parties(M);
    for(int i=0;i<M;i++) {
        int num;
        cin >> num;
        for(int j=0;j<num;j++) {
            int person;
            cin >> person;
            parties[i].push_back(person);
        }

        for(int j=1;j<num;j++) {
            unite(parties[i][0], parties[i][j]);
        }
    }

    vector<bool> truthRoot(51, false);
    for(int t : truthPeople) {
        truthRoot[find(t)] = true;
    }

    int answer = 0;
    for(int i=0;i<M;i++) {
        bool canLie = true;
        for(int person: parties[i]) {
            if(truthRoot[find(person)]) {
                canLie = false;
                break;
            }
        }
        if(canLie) answer++;
    }
    cout << answer << '\n';

    return 0;
}