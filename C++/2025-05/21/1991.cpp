#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char,vector<char>> um;

void predfs(char node) {
    char left = um[node][0];
    char right = um[node][1];

    cout << node;
    if(left != '.') predfs(left);
    if(right != '.') predfs(right);
}

void inodfs(char node) {
    char left = um[node][0];
    char right = um[node][1];
    
    if(left != '.') inodfs(left);
    cout << node;
    if(right != '.') inodfs(right);
}

void postdfs(char node) {
    char left = um[node][0];
    char right = um[node][1];
    
    if(left != '.') postdfs(left);
    if(right != '.') postdfs(right);
    cout << node;
}

int main() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        char a,b,c;
        cin >> a >> b >> c;
        um[a] = {b,c};
    }

    predfs('A');
    cout << '\n';
    inodfs('A');
    cout << '\n';
    postdfs('A');
    cout << '\n';
    return 0;
}