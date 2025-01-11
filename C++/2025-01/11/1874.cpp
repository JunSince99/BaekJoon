#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    int cur = 1;
    vector<char> answer;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;

        while (cur <= num) {
            s.push(cur++);
            answer.push_back('+');
        }
        if (s.top() == num) {
            s.pop();
            answer.push_back('-');
        } else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    for(char& a:answer) {
        cout << a << '\n';
    }
    return 0;
}