#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    map<int,vector<int>> connect;

    for (int i = 1; i <= N; i++) {
        connect[i] = {};
    }

    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    map<int, bool> visited;
    int answer = 0;

    for(const auto& vertex:connect) {
        if(!visited[vertex.first]) { //방문하지 않았다면
            visited[vertex.first] = true;
            answer++;
            queue<int> q;
            q.push(vertex.first);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int next : connect[cur]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    cout << answer << endl;
}

// #include <iostream>
// #include <map>
// #include <vector>
// #include <queue>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N,M;
//     cin >> N >> M;

//     map<int,vector<int>> connect;
//     for(int i=0;i<M;i++) {
//         int a,b;
//         cin >> a >> b;
//         if(connect.count(a)) {
//             connect[a].push_back(b);
//         } else {
//             connect[a] = {b};
//         }
//     }
//     map<int, bool> visited;
//     int answer = 0;
//     for(const auto& vertex:connect) {
//         if(!visited.count(vertex.first)) { //방문하지 않았다면
//             visited[vertex.first] = true;
//             answer++;
//             queue<int> q;
//             for(int ver:vertex.second) {
//                 if(!visited.count(ver)) {
//                     q.push(ver);
//                 }
//             }
//             while(!q.empty()) {
//                 int cur = q.front();
//                 q.pop();
//                 visited[cur] = true;
//                 vector<int> temp = connect[cur];
//                 for(int t:temp) {
//                     if(!visited.count(t)) {
//                         q.push(t);
//                     }
//                 }
//             }
//         }
//     }

//     cout << answer << endl;
// }