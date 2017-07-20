#include <bits/stdc++.h>
using namespace std;

int binasearch(vector <int> v,int l,int r,int num){
	if(l <= r){
		int mid = (l+r)/2;
		if(v[mid] == num)
			return num;
		else if(v[mid] > num)
			return binasearch(v,l,mid-1,num);
		else if(v[mid] < num)
			return binasearch(v,mid+1,r,num);
	}
	return -1;
}

int main(void){
	int n;
	cin >> n;
	vector <int> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];

	sort(v.begin(),v.end());
	int num;
	cin >> num;
	cout << binasearch(v,0,n-1,num);
	return 0;
}
