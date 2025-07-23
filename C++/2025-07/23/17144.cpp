#include <iostream>
#include <vector>
using namespace std;

int R,C,T; // 방크기 R*C, T초 후 상황 출력
int room[50][50];
vector<int> machine;

int dx[4] = {-1,0,1,0}; // 위, 오른쪽, 아래, 왼쪽
int dy[4] = {0,1,0,-1};

void micro() {
    vector<vector<int>> tempRoom(R,vector<int>(C,0));

    //모든 곳을 순회하며 0보다 크면 확산.
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(room[i][j] < 5) {
                tempRoom[i][j] += room[i][j];
                continue;
            }

            int spread = room[i][j] / 5;
            for(int n=0;n<4;n++) {
                int nx = i + dx[n];
                int ny = j + dy[n];

                if(nx<0 || nx>=R || ny<0 || ny>=C || room[nx][ny] == -1) continue;

                tempRoom[nx][ny] += spread;
                room[i][j] -= spread;
            }
            tempRoom[i][j] += room[i][j];
        }
    }

    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
        room[i][j] = tempRoom[i][j];
}

void airClean() {
    int top = machine[0];
    int bottom = machine[2];

    //위쪽
    for(int i = top-1;i>0;i--) room[i][0] = room[i-1][0];
    for(int j=0;j<C-1;j++) room[0][j] = room[0][j+1];
    for(int i = 0; i < top; i++) room[i][C-1] = room[i+1][C-1];
    for(int j=C-1;j>1;j--) room[top][j] = room[top][j-1];
    room[top][1] = 0;

    //아랫쪽
    for(int i=bottom+1;i<R-1;i++) room[i][0] = room[i+1][0];
    for(int j=0;j<C-1;j++) room[R-1][j] = room[R-1][j+1];
    for(int i=R-1;i>bottom;i--) room[i][C-1] = room[i-1][C-1];
    for(int j=C-1;j>1;j--) room[bottom][j] = room[bottom][j-1];
    room[bottom][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> room[i][j];
            if(room[i][j] == -1) {
                machine.push_back(i);
                machine.push_back(j);
            }
        }
    }

    while(T--) {
        micro();
        airClean();
    }

    int answer = 0;
    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
        if(room[i][j] != -1) answer += room[i][j];

    cout << answer;
}