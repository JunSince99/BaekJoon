#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    queue<int> q;
    for (int i=1;i<=N;i++) {
        q.push(i);
    }
    
    for(int i=1;i<K;i++) {
        q.push(q.front());
        q.pop();
    }
    cout << "<" << q.front();
    q.pop();
    while(!q.empty()) {
        for(int i=1;i<K;i++) {
        q.push(q.front());
        q.pop();
        }
        cout << ", " << q.front();
        q.pop();
    }
    cout << ">" << endl;

    return 0;
}