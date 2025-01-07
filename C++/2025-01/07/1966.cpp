#include <iostream>
#include <deque>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        int N,M;
        cin >> N >> M;

        deque<int> q;
        for(int i=0;i<N;i++){
            int num;
            cin >> num;
            q.push_back(num);
        }
        int cur_loc = M;
        int print_cnt = 0;
        while(!q.empty()) {
            if(cur_loc == 0) {
                for(int i=1;i<q.size();i++) {
                    if (q[i]>q.front()) {
                        q.push_back(q.front());
                        q.pop_front();
                        cur_loc = q.size()-1;
                        break;
                    }
                }
                if(cur_loc == 0) {
                    print_cnt++;
                    cout << print_cnt << '\n';
                    break;
                }
            } else {
                bool ispoped = false;
                for(int i=1;i<q.size();i++) {
                    if (q[i]>q.front()) {
                        q.push_back(q.front());
                        q.pop_front();
                        ispoped = true;
                        cur_loc--;
                        break;
                    }
                }
                if(!ispoped) {
                    print_cnt++;
                    q.pop_front();
                    cur_loc--;
                }
            }
        }
    }
    return 0;
}