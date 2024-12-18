#include <iostream>
#include <vector>

using namespace std;

int nx[4] = {-1,0,1,0};
int ny[4] = {0,1,0,-1};

int main() {
    // 입력단
    int N,M; // 방의 크기
    cin >> N >> M;

    int r,c,d; //로봇청소기 시작점 (r,c) / 로봇청소기 방향 d(북쪽 0, 동쪽 1, 남쪽 2, 서쪽 3)
    cin >> r >> c >> d;

    vector<vector<int>> room(N,vector<int>(M));

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> room[i][j];
        }
    }

    int count = 0;

    //동작단
    while(true) {
        //1번 지시
        if (room[r][c] == 0) {
            room[r][c] = 2;
            count++;
        }
        
        //2,3번 지시
        bool isnear = false;
        for(int i=0;i<4;i++) {
            int dx = r+nx[i];
            int dy = c+ny[i];
            if (0<=dx && dx<N && 0<=dy && dy<M && room[dx][dy] == 0) {
                isnear = true;
            }
        }
        if(isnear) {
            for (int i=0;i<4;i++) {
                if (d == 0) d=3;
                else d -= 1;
                int dx = r+nx[d];
                int dy = c+ny[d];
                if (0<=dx && dx<N && 0<=dy && dy<M && room[dx][dy] == 0) {
                    r = dx;
                    c = dy;
                    break;
                }
            }
        } else {
            int dx = r-nx[d];
            int dy = c-ny[d];
            if (0<=dx && dx<N && 0<=dy && dy<M && (room[dx][dy] == 0 || room[dx][dy] == 2)) {
                r = dx;
                c = dy;
            } else {
                break;
            }
        }
    }

    cout << count << endl;
}