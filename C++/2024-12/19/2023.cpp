#include <iostream>
#include <cmath>

using namespace std;

bool issosu(int num) {
    if (num==1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) {
			return false;
		}
	}

	return true;
}

bool isbeautysosu(int num) {
    while(num!=0) {
        if(!issosu(num)) return false;
        num /= 10;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int min = pow(10,N-1);
    int max = pow(10,N);

    for (int i=min*2;i<max;i++) {
        if (issosu(i) && isbeautysosu(i)) {
            cout << i << endl;
        }
    }
    return 0;
}