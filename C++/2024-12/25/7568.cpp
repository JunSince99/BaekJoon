#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> people(N,vector<int>(2));
    vector<int> grade(N);
    for(int i=0;i<N;i++) {
        cin >> people[i][0] >> people[i][1];
    }

    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            if (people[i][0] < people[j][0] && people[i][1] < people[j][1]) {
                grade[i] += 1;
            } else if(people[i][0] > people[j][0] && people[i][1] > people[j][1]) {
                grade[j] += 1;
            }
        }
    }

    for (int g:grade) {
        cout << g+1 << " ";
    }
    cout << '\n';
}