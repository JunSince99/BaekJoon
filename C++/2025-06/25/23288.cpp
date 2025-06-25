#include <iostream>
#include <queue>
using namespace std;

struct diceinfo{
    int x,y,dir;
};

int ans;
int N,M,K;
int maps[20][20];
int score[20][20];
int dice[6] = {1,6,5,2,4,3}; // 위, 아래, 앞, 뒤, 왼, 오
diceinfo cur = {0,0,1}; // 방향 1:동쪽 , 주사위 밑면 6으로 시작

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void roll(int d) {
    int temp;
    if(d == 0) { // 북
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    } else if(d == 1) { // 동
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    } else if(d == 2) { // 남
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    } else if(d == 3) { // 서
        temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
}

int bfs() {
    if(score[cur.x][cur.y] != 0) {
        return score[cur.x][cur.y];
    }

    int val = 1;
    queue<pair<int,int>> q;
    vector<pair<int,int>> record;
    bool visited[20][20] = {false};
    int target = maps[cur.x][cur.y];

    q.push({cur.x,cur.y});
    visited[cur.x][cur.y] = true;
    record.push_back({cur.x,cur.y});
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M || visited[nx][ny]) continue;
            if(maps[nx][ny] == target) {
                q.push({nx,ny});
                visited[nx][ny] = true;
                record.push_back({nx,ny});
                val++;
            }
        }
    }
    val = val * target;
    for(auto& r : record) {
        score[r.first][r.second] = val;
    }
    return val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    cin >> maps[i][j];

    while(K--) {
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        if(nx<0 || nx>=N || ny<0 || ny>=M) {
            cur.dir = (cur.dir+2) % 4;
            nx = cur.x + dx[cur.dir];
            ny = cur.y + dy[cur.dir];
        }
        cur.x = nx; cur.y = ny;
        roll(cur.dir);

        ans += bfs(); // 현재 자리의 점수 더해주기

        if(dice[1] > maps[nx][ny])
            cur.dir = (cur.dir+1) % 4;
        else if(dice[1] < maps[nx][ny])
            cur.dir = (cur.dir+3) % 4;
    }
    cout << ans;
}