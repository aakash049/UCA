#include <stdio.h>
#include <assert.h>

int binarySearch(int arr[], int length, int num);

int main()
{
	int a[] = {1, 2, 3, 6, 7};

	printf("%d ", binarySearch(a, 5, 9));
	return 0;
}

