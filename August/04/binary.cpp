#include <bits/stdc++.h>
using namespace std;

void binarySequence(int n){
	queue <string> q;
    q.push("1");
    for(int i = 0; i < n; i++){
        string x = q.front();
        q.pop();
        cout << i+1 << " : " << x << endl;
        q.push(x+"0");
        q.push(x+"1");
    }
}

int main(){
    int n;
    cin >> n;
    binarySequence(n);
    return 0;
}
