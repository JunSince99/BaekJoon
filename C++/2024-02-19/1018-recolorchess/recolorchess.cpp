#include <iostream>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];

int wfbCheck(int x, int y){
    int result = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[x+i][y+j]!=WB[i][j])
                result += 1;
        }
    }
    return result;
}

int bfbCheck(int x, int y){
    int result = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[x+i][y+j]!=BW[i][j])
                result += 1;
        }
    }
    return result;
}

int main(){
    int n,m;
    cin >> n >> m;
    int min_val = 64;
    for(int i = 0; i<n; i++){
        cin >> board[i];
    }
    
    for(int i = 0; i + 7 < n; i++){
        for(int j = 0; j + 7 < m; j++){
            int temp;
            temp = min(wfbCheck(i,j),bfbCheck(i,j));
            if(temp <min_val)
                min_val = temp;
        }
    }
    cout << min_val << '\n';
}