#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<int> trees(N);
    int highest = 0;
    for(int i=0;i<N;i++) {
        cin >> trees[i];
        highest = max(highest,trees[i]);
    }

    int i=0;
    int j=highest;
    int answer = 0;

    while(i<=j) {
        int mid = (i+j)/2;

        long long wood = 0;
        for(int tree:trees) {
            if (tree > mid)
                wood += (tree-mid);
        }

        if (wood >= M) {
            answer = mid;
            i = mid + 1;
        } else {
            j = mid - 1; 
        }
    }

    cout << answer << endl;
}