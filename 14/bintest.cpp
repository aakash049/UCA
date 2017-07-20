#include <bits/stdc++.h>
using namespace std;

int binasearch(int *v,int l,int r,int num){
	if(r < l)
		return 0;

	int mid = (l+r)/2;
	if(v[mid] == num)
		return 1;
	else if(v[mid] > num)
		return binasearch(v,l,mid-1,num);
	return binasearch(v,mid+1,r,num);
}

int main(void){
	int n=5;
	int v[] = {1,2,3,4,5};

	//sort(v.begin(),v.end());
	for(int i=-10;i<=10;i++)
		cout << i << " " << binasearch(v,0,n-1,i) << endl;
	return 0;
}
