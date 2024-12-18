#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nx[4] = {0,0,-1,1};
int ny[4] = {-1,1,0,0};

struct input{
    int x,y,far;
    bool power;
};

int main() {
    int N,M;
    cin >> N >> M;
    vector<string> maps(N);
    vector<vector<bool>> visited(N,vector<bool>(M, false));
    for (int i=0;i<N;i++) {
        cin >> maps[i];
    }
    queue<input> q;
    q.push({0,0,1,true});
    while(!q.empty()) {
        input cur = q.front();
        q.pop();

        if (cur.x == N-1 && cur.y == M-1) {
            cout << cur.far << endl;
            return 0;
        }

        for (int i=0;i<4;i++) {
            int dx = cur.x + nx[i];
            int dy = cur.y + ny[i];
            if (0<=dx && dx<N && 0<=dy && dy<M && !visited[dx][dy]) {
                if (maps[dx][dy] == '0') {
                    q.push({dx,dy,cur.far+1,cur.power});
                    visited[dx][dy] = true;
                } else {
                    if (cur.power) {
                        q.push({dx,dy,cur.far+1,!cur.power});
                        visited[dx][dy] = true;
                    }
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}