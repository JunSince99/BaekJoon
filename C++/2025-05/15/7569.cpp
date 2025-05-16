#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {-1,1,0,0,0,0};
int dz[6] = {0,0,0,0,-1,1};

using namespace std;

struct tomato {
    int x;
    int y;
    int z;
    int Day;
};

bool isalltomato(const vector<vector<vector<int>>> &t) {
    for(int i=0;i<t.size();i++) {
        for(int j=0;j<t[0].size();j++) {
            for(int k=0;k<t[0][0].size();k++) {
                if(t[i][j][k] == 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N,H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> tomatos(H, vector<vector<int>>(N, vector<int>(M)));
    queue<tomato> q;

    for(int i=0;i<H;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                cin >> tomatos[i][j][k];
                if(tomatos[i][j][k] == 1) {
                    q.push({i,j,k,0});
                }
            }
        }
    }
    int minDay = -1;
    while(!q.empty()) {
        tomato cur = q.front();
        q.pop();

        minDay = max(minDay, cur.Day);

        for(int i=0;i<6;i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            if(0<=nx && nx<H && 0<=ny && ny<N && 0<=nz && nz<M && tomatos[nx][ny][nz]==0) {
                q.push({nx,ny,nz,cur.Day+1});
                tomatos[nx][ny][nz] = 1;
            }
        }
    }

    if(isalltomato(tomatos)) {
        cout << minDay << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}