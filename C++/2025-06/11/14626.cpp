#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string nums;
    cin >> nums;

    int isone = true;
    int sum = 0;
    int star;
    for(int i=0;i<nums.size()-1;i++) {
        if(nums[i] == '*') {
            if(isone) {
                star = 1;
                isone = !isone;
            } else {
                star = 3;
                isone = !isone;
            } 
        } else {
            if(isone){
                sum += nums[i]-'0';
                isone = !isone;
            } else {
                sum += (nums[i]-'0') * 3;
                isone = !isone;
            } 
        }
    }

    for(int i=0;i<10;i++) {
        int check = nums[nums.size()-1]-'0';
        if((sum+(star*i)+check)%10 == 0) {
            cout << i;
            return 0;
        }
    }
}