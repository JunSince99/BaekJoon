#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M,K;
int maps[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<M;j++) {
            maps[i][j] = temp[j] - '0';
        }
    }
    
    
    
}