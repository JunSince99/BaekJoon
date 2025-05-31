#include <iostream>
#include <queue>
using namespace std;

int N,M,K;
int R, C;
int notebook[40][40];
int sticker[10][10];
int temp[10][10];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for(int t=0;t<K;t++) {
        cin >> R >> C;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                cin >> sticker[i][j];
        //노트북 모든 점 순회
        bool isattach = false;
        for(int rot = 0; rot<4;rot++) {
            for(int i=0;i<=N-R;i++) {
                for(int j=0;j<=M-C;j++) {
                    bool canattach = true;
                    for(int r = 0; r < R; r++)
                        for(int c = 0; c < C; c++)
                            if(sticker[r][c] == 1 && notebook[r+i][c+j]) canattach = false;
                    if(canattach) {
                        for(int r = 0; r < R; r++){
                            for(int c = 0; c < C; c++) {
                                if(sticker[r][c] == 1)
                                    notebook[i+r][j+c] = 1;
                            }
                        }
                        isattach = true;
                        break;
                    }
                }
                if(isattach) break;
            }
            if(isattach) break;
            //돌리기기
            for(int x = 0; x < R; ++x)
                for(int y = 0; y < C; ++y)
                    temp[y][R-1-x] = sticker[x][y];
            // temp -> sticker 복사
            swap(R, C);
            for(int x = 0; x < R; ++x)
                for(int y = 0; y < C; ++y)
                    sticker[x][y] = temp[x][y];
        }
        

    }
    int cnt=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(notebook[i][j] == 1) cnt++;
        }
    }

    cout << cnt;
}