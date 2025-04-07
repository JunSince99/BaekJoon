#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> stair(N);
    vector<int> score(N);
    for(int n=0;n<N;n++) {
        cin >> stair[n];
    }

    score[0] = stair[0];
    if(N>1)
        score[1] = stair[0] + stair[1];
    if(N>2)
        score[2] = max(stair[0]+stair[2], stair[1]+stair[2]);
    for(int i=3;i<N;i++) {
        score[i] = max(score[i-2]+stair[i], score[i-3]+stair[i-1]+stair[i]);
    }

    cout << score[N-1] << '\n';


    return 0;
}