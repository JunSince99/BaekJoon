#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

struct Point {
    int x, y, day;
};

int tomato(vector<vector<int>>& box, int M, int N) {
    array<array<int, 2>,4> coor = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};;
    queue<Point> q; //현재 위치, 일 수
    int day = 0;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++) {
            if (box[i][j] == 1) {
                q.push({i,j,0});
            }
        }
    }

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        day = max(day, cur.day);

        for(array a:coor) {
            int nx = cur.x + a[0];
            int ny = cur.y + a[1];
            if(0<=nx and nx<N and 0<=ny and ny <M) {
                if(box[nx][ny] == 0) {
                    box[nx][ny] = 1;
                    q.push({nx,ny,cur.day+1});
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                return -1;
            }
        }
    }

    return day;
}

int main() {
    int M,N;
    cin >> M >> N;
    vector<vector<int>> boxes(N,vector<int>(M));
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++) {
            cin >> boxes[i][j];
        }
    }
    cout << tomato(boxes,M,N);
    return 0;
}