#include <iostream>
#include <deque>
using namespace std;

deque<bool> sharp[4];
int k;

void turning(int snum, int dir) {
    if(dir == 1) {
        sharp[snum].push_front(sharp[snum].back());
        sharp[snum].pop_back();
    } else if (dir == -1) {
        sharp[snum].push_back(sharp[snum].front());
        sharp[snum].pop_front();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<4;i++) {
        string temp;
        cin >> temp;
        for(char t : temp) {
            sharp[i].push_back(t-'0');
        }
    }
    cin >> k;
    while(k--) {
        int cmd,isclock;
        cin >> cmd >> isclock;
        cmd--;
        
        switch(cmd) {
            case 0:
                turning(0,isclock);
                if(sharp[0][2+isclock] != sharp[1][6]) {
                    turning(1,-isclock);
                    if(sharp[1][2-isclock] != sharp[2][6]) {
                        turning(2,isclock);
                        if(sharp[2][2+isclock] != sharp[3][6]) turning(3,-isclock);
                    }
                }
                break;
            case 1:
                turning(1,isclock);
                if(sharp[1][6+isclock] != sharp[0][2]) turning(0,-isclock);
                if(sharp[1][2+isclock] != sharp[2][6]) {
                    turning(2,-isclock);
                    if(sharp[2][2-isclock] != sharp[3][6]) turning(3,isclock);
                }
                break;
            case 2:
                turning(2,isclock);
                if(sharp[2][2+isclock] != sharp[3][6]) turning(3,-isclock);
                if(sharp[2][6+isclock] != sharp[1][2]) {
                    turning(1,-isclock);
                    if(sharp[1][6-isclock] != sharp[0][2]) turning(0,isclock);
                }
                break;
            case 3:
                turning(3,isclock);
                if(sharp[3][6+isclock] != sharp[2][2]) {
                    turning(2,-isclock);
                    if(sharp[2][6-isclock] != sharp[1][2]) {
                        turning(1,isclock);
                        if(sharp[1][6+isclock] != sharp[0][2]) turning(0,-isclock);
                    }
                }
                break;
        }
    }
    int ans = 0;
    for(int i=0;i<4;i++) {
        if(sharp[i].front() == 1) {
            if(i==0) ans += 1;
            else if(i==1) ans += 2;
            else if(i==2) ans += 4;
            else if(i==3) ans += 8;
        }
    }

    cout << ans;
} 