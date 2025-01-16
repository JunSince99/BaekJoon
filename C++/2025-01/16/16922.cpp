#include <iostream>
#include <set>

using namespace std;

int roma[4] = {1,5,10,50};
set<int> numbers;

void rome(int left, int sum, int start_index) {
    if(left == 0) {
        numbers.insert(sum);
        return;
    }

    for(int i=start_index;i<4;i++) {
        rome(left-1,(sum+roma[i]),i);
    }
}

int main() {
    int N;
    cin >> N;

    rome(N,0,0);

    cout << numbers.size() << endl;
}