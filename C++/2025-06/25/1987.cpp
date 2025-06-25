// 백트래킹으로 풀어야할 것 같다
// unordered_map에 방문 여부를 저장
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int ans;
int R, C;
char maps[20][20];
bool um[26];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x, int y, int depth) {
    ans = max(ans, depth);

    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=R || ny<0 || ny>=C || um[maps[nx][ny]-'A']) continue;

        um[maps[nx][ny]-'A'] = true;
        dfs(nx,ny,depth+1);
        um[maps[nx][ny]-'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for(int i=0;i<R;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<C;j++) {
            maps[i][j] = temp[j];
        }
    }

    char first = maps[0][0] - 'A';
    um[first] = true;
    dfs(0, 0, 1);

    cout << ans;
}