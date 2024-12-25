#include <iostream>
#include <set>

using namespace std;

struct setcompare
{
    bool operator()(const string &a, const string &b) const {
        if (a.size()==b.size()) {
            return a<b;
        }
        return a.size() < b.size();
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    set<string,setcompare> dict;
    for(int i=0;i<N;i++) {
        string S;
        cin >> S;
        dict.insert(S);
    }

    for(const string& word:dict) {
        cout << word << endl;
    }
}