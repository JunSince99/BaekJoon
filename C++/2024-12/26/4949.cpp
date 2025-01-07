#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (true) {
        // 한 줄 입력받기
        string input;
        getline(cin, input);

        // 입력이 "."만 있을 경우 프로그램 종료
        if (input == ".") {
            break; // 프로그램 종료
        }

        stack<char> st;

        // 문자열 처리
        for (char c : input) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            } else if (c == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            } else if (c == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            } else if (c == ')' || c == ']' || c == '}') {
                st.push(c); // 균형이 맞지 않는 닫는 괄호
            }
        }

        // 결과 출력
        if (st.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}