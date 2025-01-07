#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    double N;
    cin >> N;

    vector<double> scores(N);
    double cut = round(N*15/100);
    double answer = 0;
    for(int i=0;i<N;i++){
        double num;
        cin >> num;
        scores[i] = num;
    }
    sort(scores.begin(), scores.end());
    for(int i=0;i<N;i++) {
        if (i>=cut && i<N-cut) {
            answer += scores[i];
        }
    }

    answer = round(answer/(N-(cut*2)));
    cout << answer << endl;

    return 0;
}
