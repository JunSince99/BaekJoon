#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> land(N, vector<int>(M));
    int highest = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> land[i][j];
            if (land[i][j] > highest)
                highest = land[i][j];
        }
    }

    int minTime=1e9;
    int height = 0;
    for(int t=0;t<=highest;t++) {
        int inventory = B;
        int time = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(land[i][j] > t) {
                    time += (land[i][j]-t) * 2;
                    inventory += land[i][j] - t;
                } else if(land[i][j] < t) {
                    time += t - land[i][j];
                    inventory -= t - land[i][j];
                }
            }
        }
        if (inventory < 0)
            continue;
        else {
            if (minTime >= time) {
                minTime = time;
                height = t;
            }
        }
    }

    cout << minTime << ' ' << height << '\n';
}