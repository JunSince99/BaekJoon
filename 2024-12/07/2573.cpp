#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nx[4] = {1,-1,0,0};
int ny[4] = {0,0,1,-1};

struct Coor {
    int x,y;
};

bool isSeparate(const vector<vector<int>>& maps, int N, int M) {
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    queue<Coor> q;
    int count = 0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (maps[i][j]>0 && visited[i][j]==false) {
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()) {
                    Coor cur = q.front();
                    q.pop();
                    for (int k=0;k<4;k++) {
                        int dx = cur.x + nx[k];
                        int dy = cur.y + ny[k];
                        if (0<=dx && dx<N && 0<=dy && dy<M && visited[dx][dy]==false && maps[dx][dy]>0) {
                            q.push({dx,dy});
                            visited[dx][dy] = true;
                        }
                    }
                }
                count++;
                if (count >= 2) return true;
            }
        }
    }
    
    return false;
}

int solution(vector<vector<int>>& maps, int N, int M) {
    int years = 0;
    bool isAllicemelt = false;

    if(isSeparate(maps,N,M)) return 0;

    while(!isAllicemelt) {
        years += 1;
        isAllicemelt = true;
        vector<vector<int>> add_map(N,vector<int>(M,0));
        for (int i = 0; i<N;i++) { //얼음 녹일 양 저장
            for (int j=0; j<M;j++) {
                if (maps[i][j]>0) {
                    isAllicemelt = false;
                    int howmelt = 0;
                    for (int k=0;k<4;k++) {
                        int dx = i + nx[k];
                        int dy = j + ny[k];
                        if (0<=dx && dx<N && 0<=dy && dy<M && maps[dx][dy]<=0) {
                            howmelt++;
                        }
                    }
                    add_map[i][j] = howmelt;
                }
            }
        }

        for (int i = 0; i<N;i++) { //녹인거 적용
            for (int j=0; j<M;j++) {
                maps[i][j] -= add_map[i][j];
            }
        }
        if(isSeparate(maps,N,M)) return years;
    }

    return 0;
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> maps(N,vector<int>(M));
    for (int i = 0; i<N;i++) {
        for (int j=0; j<M;j++) {
            cin >> maps[i][j];
        }
    }

    cout << solution(maps,N,M) << endl;
}

// vector<vector<int>> mapss = {
    //     {0, 0, 0, 0, 0, 0, 0},
    //     {0, 2, 4, 0, 3, 0, 0},
    //     {0, 3, 0, 0, 5, 2, 0},
    //     {0, 7, 6, 1, 4, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0}
    // };
    // int answer = isSeparate(mapss,5,7);
    // cout << answer << endl;