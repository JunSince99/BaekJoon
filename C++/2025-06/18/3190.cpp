#include <iostream>
#include <deque>
using namespace std;

int n,k,l;
int board[100][100]; //0.빈곳 1.사과 2.몸통
pair<int,char> cmd[100];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int nextcmd = 0;

int dir = 0;
int time = 0;

deque<pair<int,int>> snake;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0;i<k;i++) {
        int a,b;
        cin >> a >> b;
        board[a-1][b-1] =  1;
    }
    cin >> l;
    for(int i=0;i<l;i++) {
        int a;
        char b;
        cin >> a >> b;
        cmd[i] = {a,b};
    }
    board[0][0] = 2;
    snake.push_back({0,0});
    while(true) {
        time++;
        int nx = snake.back().first + dx[dir];
        int ny = snake.back().second + dy[dir];
        if(0>nx || nx>=n || 0>ny || ny>=n || board[nx][ny] == 2) {
            cout << time << '\n';
            return 0;
        }
        if(board[nx][ny] == 1) {
            snake.push_back({nx,ny});
            board[nx][ny] = 2;
        } else if(board[nx][ny] == 0) {
            snake.push_back({nx,ny});
            board[nx][ny] = 2;
            board[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }
        if(nextcmd<l && cmd[nextcmd].first == time) {
            if(cmd[nextcmd].second == 'L') {
                dir = (dir+3) % 4;
                nextcmd++;
            } else if(cmd[nextcmd].second == 'D') {
                dir = (dir+1) % 4;
                nextcmd++;
            }
        }
    }
}