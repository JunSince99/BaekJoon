#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string,int> people;
    for(int i=0;i<N;i++) {
        string name;
        cin >> name;
        people[name] = 1;
    }
    vector<string> answer;
    for(int i=0;i<M;i++) {
        string name;
        cin >> name;
        if(people[name] == 1) {
            answer.push_back(name);
        }
    }
    sort(answer.begin(),answer.end());
    cout << answer.size() << '\n';
    for(string& a:answer) {
        cout << a << '\n';
    }

    return 0;
}