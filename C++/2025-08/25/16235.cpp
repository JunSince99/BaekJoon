#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N, M, K; // N x N 땅에 M개의 나무를 심고, K년 뒤의 나무 갯수 확인 가즈아
int land[10][10]; // 땅의 양분 정보
int A[10][10]; // 겨울 양분 리필량

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> A[i][j];
            land[i][j] = 5;
        }
    }

    deque<int> trees[10][10];
    for(int i=0;i<M;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        
        trees[x-1][y-1].push_back(z);
    }

    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            if (!trees[i][j].empty())
                sort(trees[i][j].begin(), trees[i][j].end());

    while(K--) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if (trees[i][j].empty()) continue;
                int dead = 0;
                deque<int> next;
                while(!trees[i][j].empty()) {
                    int age = trees[i][j].front(); trees[i][j].pop_front();
                    if(land[i][j] >= age) {
                        land[i][j] -= age;
                        next.push_back(age+1);
                    } else {
                        dead += age/2;
                    }
                }
                land[i][j] += dead;
                trees[i][j].swap(next);
            }
        }
        // [가을] 나이가 5의 배수인 나무가 주변 8개 칸에 나이 1 나무를 추가한다.
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(trees[i][j].empty()) continue;

                int sexnamu = 0;
                for(int& age:trees[i][j]) if(age % 5 == 0) sexnamu++;
                if(sexnamu == 0) continue;

                for(int d=0;d<8;d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    for(int c=0;c<sexnamu;c++) trees[nx][ny].push_front(1);
                }

            }
        }
        // [겨울] 모든 땅에 A배열 양분을 추가한다.
        for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            land[i][j] += A[i][j];
    }

    long long ans = 0;
    for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
        ans += trees[i][j].size();

    cout << ans << '\n';
    return 0;
}