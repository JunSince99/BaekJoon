#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int hx[8] = {-1,-2,-2,-1,1,2,2,1};
int hy[8] = {-2,-1,1,2,2,1,-1,-2};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int k;
    cin >> k;
    int w,h;
    cin >> h >> w;
    vector<vector<int>> maps(w,vector<int>(h));
    vector<vector<vector<bool>>> visited(w,vector<vector<bool>>(h,vector<bool>(k+1,false)));
    for (int i=0;i<w;i++) {
        for (int j=0;j<h;j++) {
            cin >> maps[i][j];
        }
    }
    queue<tuple<int, int, int, int>> q; // x, y, far, k
    q.push({0,0,0,0});
    visited[0][0][0] = true;

    while(!q.empty()) {
        tuple cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int far = get<2>(cur);
        int last_k = get<3>(cur);

        if (x==w-1 && y==h-1) {
            cout << far << "\n";
            return 0;
        }

        if (last_k<k) {
            for(int i=0;i<8;i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (0<=nx && nx < w && 0<=ny && ny<h && maps[nx][ny] == 0 && visited[nx][ny][last_k+1] == false) {
                    q.push({nx,ny,far+1,last_k+1});
                    visited[nx][ny][last_k+1] = true;
                }
            }
        }
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0<=nx && nx < w && 0<=ny && ny<h && maps[nx][ny] == 0 && visited[nx][ny][last_k] == false) {
                q.push({nx,ny,far+1,last_k});
                visited[nx][ny][last_k] = true;
            }
        }
    }
    cout << -1 << "\n";
    
    return 0;
}