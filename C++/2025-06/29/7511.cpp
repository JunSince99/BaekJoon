#include <iostream>
#include <vector>
using namespace std;

int find(int x, vector<int>& p) {
    if(p[x] == -1) return x;
    return p[x] = find(p[x], p);
}

void uni(int x, int y, vector<int>& p) {
    x = find(x, p);
    y = find(y, p);
    if(x != y) p[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cout << "Scenario " << t << ":\n";

        int n,k,m;
        cin >> n >> k;
        vector<int> p(n,-1);
        while(k--) {
            int a,b;
            cin >> a >> b;
            uni(a,b,p);
        }
        cin >> m;
        while(m--) {
            int a,b;
            cin >> a >> b;
            if(find(a,p) == find(b,p)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        cout << '\n';
    }
}