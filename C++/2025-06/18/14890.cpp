#include <iostream>
using namespace std;

int ans;
int n,l;
int maps[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin >> maps[i][j];

    // 행 체크
    for(int i=0;i<n;i++) {
        bool road = true;
        bool used[100] = {};
        for(int j=0;j<n-1;j++) {
            // 다음이 같은 높이일 때
            if(maps[i][j] == maps[i][j+1]) continue;
            //다음이 한 칸 낮을 때
            if(maps[i][j] == maps[i][j+1]+1) {
                for(int k=1;k<=l;k++) {
                    if(j+k<n && maps[i][j+k] == maps[i][j+1] && !used[j+k]) continue;
                    else {
                        road = false;
                        break;
                    }
                }
                if(!road) break;
                for(int k=1;k<=l;k++) used[j+k] = true;
            } else if(maps[i][j] == maps[i][j+1]-1) { // 다음이 한 칸 높을 떄
                for(int k=0;k<l;k++) {
                    if(j-k >= 0 && maps[i][j-k] == maps[i][j] && !used[j-k]) continue;
                    else {
                        road = false;
                        break;
                    }
                }
                if(!road) break;
                for(int k=0;k<l;k++) used[j-k] = true;
            } else {
                road = false;
                break;
            } 
        }
        if(road) ans++;
    }
    // 열 체크
    for(int j=0;j<n;j++) {
        bool road = true;
        bool used[100] = {};
        for(int i=0;i<n-1;i++) {
            if(maps[i][j] == maps[i+1][j]) continue; // 다음이 같은 높이일 때
            
            if(maps[i][j] == maps[i+1][j]+1) {// 다음이 한 칸 낮을 때
                for(int k=1;k<=l;k++) {
                    if(i+k<n && maps[i+k][j] == maps[i+1][j] && !used[i+k]) continue;
                    else {
                        road = false;
                        break;
                    }
                }
                if(!road) break;
                for(int k=1;k<=l;k++) used[i+k] = true;
            } else if(maps[i][j] == maps[i+1][j]-1) { // 다음이 한 칸 높을 때
                for(int k=0;k<l;k++) {
                    if(i-k >= 0 && maps[i-k][j] == maps[i][j] && !used[i-k]) continue;
                    else {
                        road = false;
                        break;
                    }
                }
                if(!road) break;
                for(int k=0;k<l;k++) used[i-k] = true;
            } else {
                road = false;
                break;
            }
        }
        if(road) ans++;
    }
    //출력
    cout << ans;
}