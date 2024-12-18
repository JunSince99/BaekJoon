#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> teams;
vector<int> team;

void btr(int num, vector<vector<int>>& perstats) {
    if (team.size() == N/2) {
        int temp = 0;
        for (int i=0;i<N/2-1;i++) {
            for (int j=i+1;j<N/2;j++) {
                temp += perstats[team[i]-1][team[j]-1]+perstats[team[j]-1][team[i]-1];
            }
        }
        teams.push_back(temp);
    } else {
        for (int i=num+1;i<=N;i++) {
            team.push_back(i);
            btr(i,perstats);
            team.pop_back();
        }
    }
}

int minteam(vector<int> t) {
    int a=0,b=t.size()-1;
    int less = 1000;
    while(a<b) {
        less = min(less, abs(t[a++]-t[b--]));
    }
    return less;
}

int main() {
    cin >> N;
    vector<vector<int>> perstats(N,vector<int>(N));

    for(int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> perstats[i][j];
        }
    }

    btr(0,perstats);
    
    cout << minteam(teams) << endl;

    return 0;
}