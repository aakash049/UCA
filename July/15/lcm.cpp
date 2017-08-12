#include <bits/stdc++.h>
using namespace std;

int gcd(int n,int m){
	if(n%m == 0)
		return m;
	return gcd(m,m/n);
}
int main(){
	int n,m;
	cin >> n >> m;
	cout << (n*m)/gcd(n,m);
}
