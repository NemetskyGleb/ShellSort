#include <iostream>
#include "foo.h"

const int N = 8;
int main()
{
	//int *arr = new int[N];
	//RandomArr(arr, N, 10);
	int arr[N] = { 5, -2, 1, 3, 4, 6, 9, 10 };
	PrintArr(arr, N);
	ShellSort(arr, N);
	PrintArr(arr, N);
	std::cin.get();	
	return 0;
}