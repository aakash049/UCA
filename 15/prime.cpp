#include <iostream>
using namespace std;

int main(){
	int n=101;
	wow:
		while(n--){
			for(int i=2;i*i <= n; i++)
			{
				if(n%i==0)
				{
					cout << n << " IS NOT A PRIME\n";
					goto wow;
				}
			}
			cout << n << " IS A PRIME\n";
		}
	return 0;
}
