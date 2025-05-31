#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int ans = 1e9;
char room[8][8];
vector<pair<int,int>> cctv;

struct picked {
    int cx;
    int cy;
    int dirx;
    int diry;
};

vector<picked> pc;

void recur(int idx) {
    if(idx == cctv.size()) {
        int cnt=0;
        char temp[8][8];
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                temp[i][j] = room[i][j];
            }
        }
        
        for(auto pic : pc) {
            pic.cx += pic.dirx;
            pic.cy += pic.diry;
            while(0<=pic.cx && pic.cx<N && 0<=pic.cy && pic.cy<M && temp[pic.cx][pic.cy] != '6') {
                if(temp[pic.cx][pic.cy] == '0')temp[pic.cx][pic.cy] = '#';
                pic.cx += pic.dirx;
                pic.cy += pic.diry;
            }
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(temp[i][j] == '0') cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    char curnum = room[x][y];
    if(curnum == '1') {
        pc.push_back({x,y,-1,0});
        recur(idx+1);
        pc.pop_back();
        pc.push_back({x,y,1,0});
        recur(idx+1);
        pc.pop_back();
        pc.push_back({x,y,0,-1});
        recur(idx+1);
        pc.pop_back();
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
    } else if(curnum == '2') {
        pc.push_back({x,y,-1,0});
        pc.push_back({x,y,1,0});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();

        pc.push_back({x,y,0,-1});
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
    } else if(curnum == '3') {
        pc.push_back({x,y,-1,0});
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();

        pc.push_back({x,y,0,1});
        pc.push_back({x,y,1,0});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
        
        pc.push_back({x,y,1,0});
        pc.push_back({x,y,0,-1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();

        pc.push_back({x,y,0,-1});
        pc.push_back({x,y,-1,0});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
    } else if(curnum == '4') {
        pc.push_back({x,y,-1,0});
        pc.push_back({x,y,0,-1});
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
        pc.pop_back();

        pc.push_back({x,y,-1,0});
        pc.push_back({x,y,1,0});
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
        pc.pop_back();

        pc.push_back({x,y,1,0});
        pc.push_back({x,y,0,-1});
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
        pc.pop_back();

        pc.push_back({x,y,-1,0});
        pc.push_back({x,y,0,-1});
        pc.push_back({x,y,1,0});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
        pc.pop_back();
    } else if(curnum == '5') {
        pc.push_back({x,y,-1,0});
        pc.push_back({x,y,1,0});
        pc.push_back({x,y,0,-1});
        pc.push_back({x,y,0,1});
        recur(idx+1);
        pc.pop_back();
        pc.pop_back();
        pc.pop_back();
        pc.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> room[i][j];
            if(room[i][j] != '0' && room[i][j] != '6') {
                cctv.push_back({i,j});
            }
        }
    }

    recur(0);
    cout << ans;
}