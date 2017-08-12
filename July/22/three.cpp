#include <bits/stdc++.h>
using namespace std;

int three(int arr[], int size){
    multimap <int, int> m;
    for(int i = 0; i < size; i++){
        m.insert(make_pair(arr[i],1));
    }
    for(multimap <int, int> :: iterator it = m.begin(); it != m.end(); it++){
        if(m.count(it->first) < 3)
            return it->first;
    }
    return -1;
}


int main(){
    int arr[] = {3, 3, 1, 2, 1, 1, 3};
    cout << three(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
