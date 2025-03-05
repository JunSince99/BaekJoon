#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    cin >> N >> M;

    unordered_map<string,string> pass;
    for(int n=0;n<N;n++) {
        string ID, PASS;
        cin >> ID >> PASS;
        pass[ID] = PASS;
    }
    for(int m=0;m<M;m++) {
        string ID;
        cin >> ID;
        cout << pass[ID] << '\n';
    }

    return 0;
}