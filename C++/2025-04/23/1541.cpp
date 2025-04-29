#include <iostream>
#include <sstream>

using namespace std;

int strsum(string s) {
    stringstream ts(s);
    string t;
    int answer = 0;
    while(getline(ts,t,'+')) {
        answer += stoi(t);
    }

    return answer;
}

int main() {
    int result=0;
    string str;
    cin >> str;

    stringstream ss(str);
    string temp;
    getline(ss, temp, '-');

    result += strsum(temp);

    while(getline(ss, temp, '-')) {
        result -= strsum(temp);
    }

    cout << result << '\n';

    return 0;
}