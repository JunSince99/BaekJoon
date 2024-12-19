#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    for (int i=0;i<testcases;i++) {
        int N;
        cin >> N;

        vector<string> answer;
        queue<tuple<int, int, int, string>> q;
        q.push({1,1,1,"1"});
        while(!q.empty()) {
            tuple<int, int, int, string> cur = q.front();
            q.pop();

            int temp_val = get<0>(cur);
            int val = get<1>(cur);
            int cur_loc = get<2>(cur);
            string cal = get<3>(cur);

            if (cur_loc == N) {
                if (val == 0) {
                    answer.push_back(cal);
                }
            } else {
                q.push({cur_loc+1,val+cur_loc+1,cur_loc+1, cal+"+"+to_string(cur_loc+1)});
                q.push({-(cur_loc+1),val-cur_loc-1,cur_loc+1, cal+"-"+to_string(cur_loc+1)});
                int merg;
                if(temp_val>0) {
                    merg = temp_val*10+cur_loc+1;
                    q.push({merg,val-temp_val+merg,cur_loc+1,cal+" "+to_string(cur_loc+1)});
                } else {
                    merg = temp_val*10-cur_loc-1;
                    q.push({merg,val-temp_val+merg,cur_loc+1,cal+" "+to_string(cur_loc+1)});
                }
            }
        }
        sort(answer.begin(),answer.end());
        for(string a:answer) {
            cout << a << endl;
        }
        cout << '\n';
    }

    return 0;
}