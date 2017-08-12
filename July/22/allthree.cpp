#include <bits/stdc++.h>
using namespace std;

int three(int arr[], int size){
    map <int, int> m;
    for(int i = 0; i < size; i++){
        m[arr[i]]++;
    }
    for(map <int, int> :: iterator it = m.begin(); it != m.end(); it++){
        if(it->second < 3)
            return it->first;
    }
    return -1;
}


int main(){
    int arr[] = {3, 3, 1, 2, 1, 1, 3};
    cout << three(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}

// Bitwise Implementation
/*
int Solution::singleNumber(const vector<int> &nums) {
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        int sum = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(((nums[j] >> i) & 1) == 1) {
                sum++;
                sum %= 3;
            }
        }
        if(sum != 0) {
            ans |= sum << i;
        }
    }
    return ans;
}

*/