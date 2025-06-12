#include <iostream>
using namespace std;

int N;
int A[200000];
int tmp[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        tmp[i] = A[i];
    } 


    
    for(int i=0;i<N-1;i++) {
        if(tmp[i] > tmp[i+1] && (tmp[i] + tmp[i+1]) % 2 != 0) {
            int temp = tmp[i];
            tmp[i] = tmp[i+1];
            tmp[i+1] = temp;
        }
    }
    bool isluck = true;
    for(int i=0;i<N-1;i++) {
        if(tmp[i]>tmp[i+1]){
            isluck = false;
            break;
        } 
    }
    if(isluck) cout << "So Lucky" << '\n';
    else cout << "Unlucky" << '\n';

    for(int i=0;i<N;i++){
        tmp[i] = A[i];
    } 

    for(int i=0;i<N-1;i++) {
        if(tmp[i] > tmp[i+1] && (tmp[i] + tmp[i+1]) % 2 == 0) {
            int temp = tmp[i];
            tmp[i] = tmp[i+1];
            tmp[i+1] = temp;
        }
    }
    isluck = true;
    for(int i=0;i<N-1;i++) {
        if(tmp[i]>tmp[i+1]){
            isluck = false;
            break;
        } 
    }
    if(isluck) cout << "So Lucky" << '\n';
    else cout << "Unlucky" << '\n';
}