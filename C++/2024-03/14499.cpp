#include <iostream>
#include <vector>

using namespace std;

vector<int> dice(6); // 위0 아래1 동2 서3 남4 북5
int n,m,x,y,k;
int map[21][21];
int order[1001];

void input(){
    cin >> n >> m >> x >> y >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin >> order[i];
    }
}

void diceeast(){
    dice = {dice[3], dice[2], dice[0], dice[1], dice[4], dice[5]};
}
void dicewest(){
    dice = {dice[2], dice[3], dice[1], dice[0], dice[4], dice[5]};
}
void dicesouth(){
    dice = {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]};
}
void dicenorth(){
    dice = {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]};
}

void roll(int num){
    switch (num)
    {
    case 1:
        if(y<m-1){
            diceeast();
            cout << dice[0] << '\n';
            y++;
            if(map[x][y]==0){
                map[x][y] = dice[1];
            } else{
                dice[1] = map[x][y];
                map[x][y] = 0;
            }
            
        }
        break;
    case 2:
        if(0<y){
            dicewest();
            cout << dice[0] << '\n';
            y--;
            if(map[x][y]==0){
                map[x][y] = dice[1];
            } else{
                dice[1] = map[x][y];
                map[x][y] = 0;
            }
        }
        break;
    case 3:
        if(0<x){
            dicenorth();
            cout << dice[0] << '\n';
            x--;
            if(map[x][y]==0){
                map[x][y] = dice[1];
            } else{
                dice[1] = map[x][y];
                map[x][y] = 0;
            }
        }
        break;
    case 4:
        if(x<n-1){
            dicesouth();
            cout << dice[0] << '\n';
            x++;
            if(map[x][y]==0){
                map[x][y] = dice[1];
            } else{
                dice[1] = map[x][y];
                map[x][y] = 0;
            }
        }
        break;
    }
}

int main() {
    input();
    for(int i=0;i<k;i++){
        roll(order[i]);
    }
    return 0;
}