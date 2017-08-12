#include <bits/stdc++.h>
using namespace std;

bool check(string x){
    stack <char> balance;
    if(x.size()%2 == 1)
        return false;
    for(int i = 0; i < x.size(); i++){
        if(x[i] == '{' || x[i] == '(' || x[i] == '['){
            balance.push(x[i]);
        }
        else{
            if(balance.size() == 0){
                return false;
            }
            char temp = balance.top();
            balance.pop();
            if(temp != x[i]-1 && temp != x[i]-2){
                return false;
            }
        }
    }
    return (balance.size() == 0);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string x;
        cin >> x;
        cout << (check(x)?"YES":"NO") << endl;
    }
    return 0;
}
