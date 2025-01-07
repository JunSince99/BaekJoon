#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Room {
    int minLevel;
    int maxLevel;
    set<pair<string,int>> players;

    bool canJoin(int level, int m) {
        return players.size() < m && level >= minLevel && level <= maxLevel;
    }
};

int main() {
    int p,m;
    cin >> p >> m;

    vector<Room> rooms;
    for (int i=0;i<p;i++) {
        int l;
        string n;
        cin >> l >> n;

        bool joined = false;
        // room 순회하면서 들어갈 수 있는 room 찾고 찾으면 room에 입력받은 플레이어 들어가기
        for(auto& room:rooms) {
            if(room.canJoin(l,m)) {
                room.players.insert({n,l});
                joined = true;
                break;
            }
        }
        // 들어갈 수 있는 room이 없으면 새로운 room 만들고 rooms에 추가
        if(!joined) {
            Room newroom;
            newroom.minLevel = l-10;
            newroom.maxLevel = l+10;
            newroom.players.insert({n,l});
            rooms.push_back(newroom);
        }
    }
    //rooms 돌면서 p명 다 찬 방 확인하고 출력하기
    for (const Room &room : rooms) {
        if (room.players.size() == m) {
            cout << "Started!" << endl;
        } else {
            cout << "Waiting!" << endl;
        }
        for (const auto &player : room.players) {
            cout << player.second << " " << player.first << endl; // level, nickname 출력
        }
    }

    return 0;
}