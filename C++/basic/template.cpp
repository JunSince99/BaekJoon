// 템플릿 입문
#include <iostream>
#include <string>

template <typename S>
class Vector {
    S* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new S[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가
    void push_back(S s) {
        if (capacity <= length) {
            S* temp = new S[capacity * 2];
            for (int i=0; i<length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    S operator[](int i) { return data[i]; }

    void remove(int x) {
        for (int i = x + 1; i < length ; i++) {
            data[i-1] = data[i];
        }
        length--;
    }

    int size() {return length;}

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

int main() {
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0]  << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1]  << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- string vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0]  << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1]  << std::endl;
}