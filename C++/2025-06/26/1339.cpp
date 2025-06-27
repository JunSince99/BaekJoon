// #include <iostream>
// #include <queue>
// using namespace std;

// int n;
// int idx[10];
// queue<char> words[10];
// int alphabet[26];

// int jegob(int time) {
//     int ans = 1;
//     for(int i=1;i<time;i++)
//         ans = ans * 10;
//     return ans;
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;
//     for(int i=0;i<n;i++) {
//         string temp;
//         cin >> temp;
//         for(char& s: temp) {
//             words[i].push(s);
//         }
//     }

//     int cur = 9;
//     bool isdone = false;
//     while(!isdone) {
//         // 단어 중 현재 가장 긴 것 찾기
//         // 해당 단어를 pop해주고 해당 알파벳에 cur 부여, cur--
//         // 해당 단어의 idx에 값을 더해준다.
//         // idx의 모든값을 합쳐서 출력한다.
//         int mostlong = 0;
//         int mlidx = -1;
//         for(int i=0;i<10;i++) {
//             if(words[i].size()>mostlong) {
//                 mostlong = words[i].size();
//                 mlidx = i;
//             }
//         }
//         if(mostlong == 0) break;
//         char curalpha = words[mlidx].front() - 'A';
//         words[mlidx].pop();
//         if(alphabet[curalpha] == 0) { // cur 부여, cur--
//             alphabet[curalpha] = cur--;
//         }
//         idx[mlidx] += alphabet[curalpha] * jegob(mostlong); //size가 1이면 1, size가 2면 2
//     }

//     int answer = 0;
//     for(int& i:idx)
//         answer += i;
//     cout << answer;
// }


// 그냥 무지성으로 큰 자리수부터 값을 하나씩 부여해줬는데
// 같은 자리수에 있는 다른 알파벳들끼리 가중치가 다르다.
// 예를들어 3번째, 1번째에 있는 알파벳보다
// 3번째 2번째에 있는 알파벳에 더 큰 수를 부여해야 최댓값인데
// 내 방식은 그냥 3,1에 있는게 더 앞에 있으면 거기다가 큰 수를 부여한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string word[10];
int alpha[26]; // A=0 ~ Z=25

int jegob(int time) {
    int ans = 1;
    for(int i=1;i<time;i++)
        ans = ans * 10;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> word[i];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<word[i].size();j++)
            alpha[word[i][j]-'A'] += jegob(word[i].size()-j);
    
    vector<pair<int,int>> weigh;
    for(int i=0;i<26;i++)
        weigh.push_back({alpha[i],i});
    
    sort(weigh.begin(),weigh.end(),greater());

    int cur = 9;
    for(auto& i : weigh) {
        alpha[i.second] = cur--;
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        int temp = 0;
        for(int j=0;j<word[i].size();j++) {
            temp += alpha[word[i][j]-'A'] * jegob(word[i].size()-j);
        }
        ans += temp;
    }
    cout << ans;
}