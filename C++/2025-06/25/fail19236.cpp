// #include <iostream>
// #include <tuple>
// #include <vector>
// using namespace std;

// int eat=0;

// int dx[8] = {-1,-1,0,1,1,1,0,-1};
// int dy[8] = {0,-1,-1,-1,0,1,1,1};

// struct shark{
//     int sx,sy,sdir;
// };

// void btr(vector<vector<int>> board, vector<tuple<int,int,int>> fish, shark cur, int sum) {
//     //물고기 이동
//         //fishes 순회하며 이동 진행
//             //dir 방향으로, 못가면 dir-1
//     for(int i = 1; i <= 16; i++) {
//         int cfx, cfy, dir;
//         tie(cfx,cfy,dir) = fish[i];

//         if (cfx == -1) continue; 

//         for(int t=0;t<8;t++) {
//             int nd = (dir - t + 8) % 8;
//             int nx = cfx + dx[nd];
//             int ny = cfy + dy[nd];

//             if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (nx == cur.sx && ny == cur.sy)) continue;

//             int target = board[nx][ny];

//             if (target != 0) {
//                 int tx, ty, tdir;
//                 tie(tx, ty, tdir) = fish[target];

//                 // i번 물고기는 target자리로, 방향은 nd로
//                 fish[i] = {tx, ty, nd};
//                 // target번 물고기는 i자리로, 방향은 원래 i의 방향
//                 fish[target] = {cfx, cfy, dir};

//                 board[nx][ny] = i;
//                 board[cfx][cfy] = target;
//             } else {
//                 fish[i] = {nx,ny,nd};
//                 board[nx][ny] = i;
//                 board[cfx][cfy] = 0;
//             }
//             break;
//         }
//     }
//     // 상어 이동(세가지 경우의 수)
//     bool isdone = true;
//     for(int i=1;i<4;i++) {
//         int nx = cur.sx + dx[cur.sdir] * i;
//         int ny = cur.sy + dy[cur.sdir] * i;

//         if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;
//         if (board[nx][ny] == -1) continue;
//         if (board[nx][ny] == 0) continue;

//         int tempnum = board[nx][ny];
//         int tempdir = get<2>(fish[tempnum]);

//         vector<vector<int>> nboard = board;
//         vector<tuple<int,int,int>> nfish = fish;

//         nboard[cur.sx][cur.sy] = 0; // 원래 자리 비움
//         nboard[nx][ny] = -1;
//         nfish[tempnum] = {-1,-1,-1}; // 먹힌 물고기

//         btr(nboard, nfish, {nx, ny, tempdir}, sum + tempnum);

//         isdone = false;
//     }

//     if(isdone) {
//         eat = max(eat, sum);
//         return;
//     }
//     // 이동 불가하면 최댓값 갱신후 return
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     vector<vector<int>> maps(4,vector<int>(4));
//     vector<tuple<int,int,int>> fishes(17);
//     shark S;

//     for(int i=0;i<4;i++) {
//         for(int j=0;j<4;j++) {
//             int a,b;
//             cin >> a >> b;
//             fishes[a] = {i,j,b-1};
//             maps[i][j] = a;
//         }
//     }

//     int first = maps[0][0];
//     S = {0, 0, get<2>(fishes[first])};
//     maps[0][0] = -1;
//     fishes[first] = {-1, -1, -1};

//     // 백트래킹 함수.
//     btr(maps,fishes,S,first);
//     // 최댓값 출력.
//     cout << eat;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fish {
    int x, y, dir;
    bool alive;
};

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int result = 0;

void dfs(vector<vector<pair<int,int>>> board, vector<Fish> fishes, int sx, int sy, int sd, int sum) {
    result = max(result, sum);

    // 1. 물고기 이동
    for(int num = 1; num <= 16; num++) {
        if(!fishes[num].alive) continue;
        int x = fishes[num].x;
        int y = fishes[num].y;
        int d = fishes[num].dir;

        for(int t = 0; t < 8; t++) {
            int nd = (d + t) % 8;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if(nx == sx && ny == sy) continue;
            // 교환할 대상
            int target = board[nx][ny].first;
            if(target == 0) {
                // 빈 칸이면 이동
                board[nx][ny] = {num, nd};
                board[x][y] = {0, 0};
                fishes[num] = {nx, ny, nd, true};
            } else {
                // 물고기 있으면 swap
                swap(board[x][y], board[nx][ny]);
                swap(fishes[num].x, fishes[target].x);
                swap(fishes[num].y, fishes[target].y);
                int tmp_dir = fishes[target].dir;
                fishes[num].dir = nd;
                fishes[target].dir = tmp_dir;
            }
            fishes[num].dir = nd;
            break;
        }
    }

    // 2. 상어 이동
    for(int s = 1; s <= 3; s++) {
        int nx = sx + dx[sd] * s;
        int ny = sy + dy[sd] * s;
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        if(board[nx][ny].first == 0) continue; // 빈 칸
        int next_fish = board[nx][ny].first;
        int next_dir = board[nx][ny].second;
        vector<vector<pair<int,int>>> next_board = board;
        vector<Fish> next_fishes = fishes;
        next_board[sx][sy] = {0, 0};
        next_board[nx][ny] = {-1, 0}; // 상어가 이동한 자리
        next_fishes[next_fish].alive = false;
        dfs(next_board, next_fishes, nx, ny, next_dir, sum + next_fish);
    }
}

int main() {
    vector<vector<pair<int,int>>> board(4, vector<pair<int,int>>(4));
    vector<Fish> fishes(17);
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            int a, b;
            cin >> a >> b;
            board[i][j] = {a, b-1};
            fishes[a] = {i, j, b-1, true};
        }
    }
    int first_num = board[0][0].first;
    int first_dir = board[0][0].second;
    fishes[first_num].alive = false;
    board[0][0] = {-1, 0}; // 상어
    dfs(board, fishes, 0, 0, first_dir, first_num);
    cout << result << endl;
    return 0;
}


// 이거 전체 좌표를 통째로 복사해야 되는 것 같다..
// 어떻게든 원본이 훼손되는거 같은데