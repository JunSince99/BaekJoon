#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    vector<vector<int>> maps(N,vector<int>(M));
    vector<vector<int>> answer(N,vector<int>(M,0));
    unordered_map<int,int> um;

    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        for(int j=0;j<M;j++) {
            maps[i][j] = temp[j] - '0';
            if(maps[i][j] == 1) answer[i][j] = 1;
        }
    }

    int name = 2;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            //0이면 순회하면서 name을 answer에 저장
            //map[name]에 cnt 저장
            //name++;
            if(maps[i][j] == 0 && answer[i][j] == 0) {
                int cnt = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                answer[i][j] = name;
                while(!q.empty()) {
                    int curx = q.front().first;
                    int cury = q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++) {
                        int nx = curx + dx[k];
                        int ny = cury + dy[k];

                        if(0<=nx && nx<N && 0<=ny && ny<M && answer[nx][ny] == 0) {
                            q.push({nx,ny});
                            answer[nx][ny] = name;
                            cnt++;
                        }
                    }
                }
                um[name++] = cnt;
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(answer[i][j] == 1) {
                unordered_map<int,bool> group;
                int sum = 0;
                for(int k=0;k<4;k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(0<=nx && nx<N && 0<=ny && ny<M && answer[nx][ny] != 1) {
                        if(!group[answer[nx][ny]])
                            sum += um[answer[nx][ny]];
                        group[answer[nx][ny]] = true;
                    }
                }
                cout << (sum + 1) % 10;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }
}

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N, M;
//     cin >> N >> M;
//     vector<vector<int>> maps(N,vector<int>(M));
//     vector<vector<int>> answer(N,vector<int>(M,0));

//     for(int i=0;i<N;i++) {
//         string temp;
//         cin >> temp;
//         for(int j=0;j<M;j++) {
//             maps[i][j] = temp[j] - '0';
//         }
//     }

//     for(int i=0;i<N;i++) {
//         for(int j=0;j<M;j++) {
//             if(maps[i][j] == 1) {
//                 int cnt = 1;
//                 vector<vector<bool>> visited(N,vector<bool>(M,false));
//                 queue<pair<int,int>> q;
//                 q.push({i,j});
//                 visited[i][j] = true;
//                 while(!q.empty()) {
//                     int curx = q.front().first;
//                     int cury = q.front().second;
//                     q.pop();

//                     for(int k=0;k<4;k++) {
//                         int nx = curx + dx[k];
//                         int ny = cury + dy[k];

//                         if(0<=nx && nx<N && 0<=ny && ny<M && maps[nx][ny] == 0 && !visited[nx][ny]) {
//                             q.push({nx,ny});
//                             visited[nx][ny] = true;
//                             cnt++;
//                         }
//                     }
//                 }

//                 answer[i][j] = cnt;
//             }
//         }
//     }

//     for(int i=0;i<N;i++) {
//         for(int j=0;j<M;j++) {
//             cout << answer[i][j];
//         }
//         cout << '\n';
//     }
// }

//와;; 당연히 bfs 인줄 알았는데 시간초과;;;;
//뭐지 그럼?
//아 이거 0인 부분에다가 그 덩어리 크기 다 저장해놓고
//1인 곳 상하 좌우 0인부분만 더하면 되나나