#include <iostream>
#include <vector>
using namespace std;

int n;
string cmd;
vector<pair<int,int>> maps = {{0,0}};
int startend[4] = {0, 0, 0, 0};
pair<int,int> cur = {0, 0};
int dir = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> cmd;

    for(int i=0;i<n;i++) {
        switch(cmd[i]) {
            case 'L':
                dir = (dir + 3) % 4;
                break;
            case 'R':
                dir = (dir + 1) % 4;
                break;
            case 'F':
                cur = {cur.first+dx[dir], cur.second+dy[dir]};
                maps.push_back(cur);
                if(cur.first < startend[0]) startend[0] = cur.first;
                if(cur.second < startend[1]) startend[1] = cur.second;
                if(cur.first > startend[2]) startend[2] = cur.first;
                if(cur.second > startend[3]) startend[3] = cur.second;
                break;
        }
    }

    char answer[51][51];
    for(int i=0;i<51;i++) {
        for(int j=0;j<51;j++) {
            answer[i][j] = '#';
        }
    }

    for(pair<int,int> temp : maps) {
        int x = temp.first - startend[0];
        int y = temp.second - startend[1];
        answer[x][y] = '.';
    }

    for(int i=0;i<startend[2]-startend[0]+1;i++) {
        for(int j=0;j<startend[3]-startend[1]+1;j++) {
            cout << answer[i][j];
        }
        cout << '\n';
    }
}