#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int T,n;
int stu[MAX];
int visited[MAX];
int done[MAX];
int ans;

void dfs(int cur) {
    visited[cur] = true;
    int next = stu[cur];

    if(!visited[next]) {
        dfs(next);
    } else if(!done[next]) {
        for(int i=next;i!=cur;i=stu[i]) ans--;
        ans--;
    }

    done[cur] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> stu[i];

        fill(visited+1,visited+n+1,false);
        fill(done+1,done+n+1,false);
        ans = n;
        
        for(int i=1;i<=n;i++)
            if(!visited[i]) dfs(i);

        cout << ans << '\n';
    }
}

// 일단 처음 든 생각은
// 모든 학생을 순회하며 자기 자신으로 돌아오는지 여부
// 근데 사이클에 포함 안된 애가 사이클 안으로 들어가면 무한루프인데..
// visited를 해야하나 visited 하는거 맞네
// 78%에서 시간초과...ㅠㅠ

//흠.. 정답은 맞는데 시간초과...
//visited를 매번 초기화 하지 말고
//그냥 쭉쭉 돌면서 사이클에 포함 되는 애들을 저장하면 되는거 아닐까

//dfs??