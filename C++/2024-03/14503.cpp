#include <iostream>

using namespace std;

int n,m;
int r,c,d;
int visited_count=0;
int room[50][50];
int visited[50][50];

void dfs(){

}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int stat;
            cin >> stat;
            room[i][j] = stat;
        }
    }
    visited[r][c] = 1;
    visited_count++;
    dfs();
}