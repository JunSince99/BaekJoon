#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> tang(N);
    for(int i=0;i<N;i++) {
        cin >> tang[i];
    }

    int left=0, right = 0, maxlength = 0;
    unordered_map<int, int> cnt;

    while(right < N) {
        cnt[tang[right]]++;

        while(cnt.size()>2) {
            cnt[tang[left]]--;
            if (cnt[tang[left]] == 0) {
                cnt.erase(tang[left]);
            }
            left++;
        }

        maxlength = max(maxlength, right - left + 1);
        right++;
    }

    cout << maxlength << '\n';
}