#include <bits/stdc++.h>
using namespace std;
// last element, count > n-1
bool check(string x){
    int count = 0;
    if(x[x.size()-1] == '{')
    	return false;
    if(x.size()%2 == 1)
        return false;
    for(int i = 0; i < x.size(); i++){
        if(x[i] == '{')
            count++;
        else
            count--;
    if(count < 0)
        return false;
    }
    return (count == 0);
}

int main(){
    string x;
    cin >> x;
    cout << check(x) << endl;
}
