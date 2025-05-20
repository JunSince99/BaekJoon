#include <iostream>
#include <queue>

using namespace std;

int D(int nn) {
    return (nn*2) % 10000;
}

int S(int nn) {
    if (nn == 0) return 9999;
    else return nn - 1;
}

int L(int nn) {
    return (nn%1000) * 10 + (nn / 1000);
}

int R(int nn) {
    return (nn%10) * 1000 + (nn/10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int A,B;
        cin >> A >> B;

        queue<pair<int, string>> q;
        bool visited[10000] = {false};

        q.push({A,""});
        visited[A] = true;
        while(!q.empty()) {
            pair<int, string> cur = q.front();
            q.pop();

            if(cur.first == B) {
                cout << cur.second << '\n';
                break;
            }

            int d = D(cur.first),s=S(cur.first),l=L(cur.first),r=R(cur.first);
            if(!visited[d]) {
                q.push({d,cur.second+"D"});
                visited[d] = true;
            }
            if(!visited[s]) {
                q.push({s,cur.second+"S"});
                visited[s] = true;
            }
            if(!visited[l]) {
                q.push({l,cur.second+"L"});
                visited[l] = true;
            }
            if(!visited[r]) {
                q.push({r,cur.second+"R"});
                visited[r] = true;
            }
        }
    }

    return 0;
}