#include <iostream>

using namespace std;

int main() {
    int n,m;
    int cards[101];
    int result = 0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> cards[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(cards[i]+cards[j]+cards[k] > result && cards[i]+cards[j]+cards[k] <=m)
                    result = cards[i]+cards[j]+cards[k];
            }
        }
    }
    cout << result << '\n';
}