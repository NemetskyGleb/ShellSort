#include <iostream>
#include <ctime>
#include "foo.h"
void RandomArr(int *arr, int n, int d) {
	std::srand(time(0));
  for (int i = 0; i < n; ++i)
	  arr[i] = std::rand() % d;
}
void PrintArr(int *arr, int n) {
  for (int i = 0; i < n; ++i)
	  std::cout << arr[i] << " ";
  std::cout << std::endl;
}
void ShellSort(int *arr, int n){
	int step, i, j, steparr[40];
	int s;
	s = FormStep(steparr, n);
	while (s >= 0){
		step = steparr[s--];
		for (i = step; i < n; i++){
			int temp = arr[i];
			for (j = i - step; (j >= 0) && (arr[j] > temp); j -= step)
				arr[j + step] = arr[j];
			arr[j + step] = temp;
		}
	}
	InsertionSort(arr, n);
}
int FormStep(int *inc, int n){
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
  	do {
    	if (++s % 2) {
      	inc[s] = 8*p1 - 6*p2 + 1;
    	} 
    	else {
      	inc[s] = 9*p1 - 9*p3 + 1;
      	p2 *= 2;
      	p3 *= 2;
    }
	p1 *= 2;
  } while(3*inc[s] < n);  
	if (s > 0)
		return --s;
	else return 0;
}
void InsertionSort(int *arr, int n){
	int i = 1;
	while(i < n) {
	    int x = arr[i];
	    int j = i - 1;
	    while ( j >= 0 && arr[j] > x){
	    	arr[j + 1] = arr[j];
	    	j--;
	    }
	    arr[j + 1] = x;
	    i++;
	}
}
