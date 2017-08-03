#include <bits/stdc++.h>
using namespace std;

int postfix(string x){
    stack <int> post;
    for(int i = 0; i < x.size(); i++){
        if(x[i] >= '0' && x[i] <= '9'){
            post.push(x[i]-'0');
        }
        else{
            int n1 = post.top();
            post.pop();
            int n2 = post.top();
            post.pop();
            if(x[i] == '*')
                post.push(n1*n2);
            else if(x[i] == '+')
                post.push(n1+n2);
            else if(x[i] == '-')
                post.push(n2-n1);
            else
                post.push(n2/n1);
        }
    }
    return post.top();
}

int main(){
    string x;
    x = "231*+9-";
    cout << postfix(x);
}
