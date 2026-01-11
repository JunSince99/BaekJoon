#include <iostream>
#include <string.h>

class string {
    char *str;
    int len;

public:
    string(char c, int n);
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);
    void copy_string(const string &s);
    void show_str();
};
string::string(char c, int n)
{
    len = n;
    str = new char[len + 1];
    for(int i=0;i<len;i++) str[i] = c;
    str[len] = '\0';
}
string::string(const char *s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}
string::string(const string &s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}
string::~string() {
    if(str) delete[] str;
}
void string::add_string(const string &s) {
    int total_len = len + s.len;

    char *temp = new char[total_len + 1];

    strcpy(temp, str);
    strcat(temp, s.str);

    if(str) delete[] str;

    str = temp;
    len = total_len;
}
void string::copy_string(const string &s) {
    if (str) delete[] str;

    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);
}
void string::show_str() {
    std::cout << std::endl << "Len : " << len << '\n';
    std::cout << "str : " << str << '\n';
}

int main() {
    string a('a', 5);
    string b("bbbb");

    a.show_str();
    b.show_str();

    a.copy_string(b);

    a.show_str();
    b.show_str();

    a.add_string(b);

    a.show_str();
    b.show_str();
}