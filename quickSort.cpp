
#include <windows.h> 
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
void QuickSort(int* arr, int right, int left = 0) {
	if (left >= right)return;
	int marker = left - 1;
	for (int index = left; index <= right; index++) {
		if (arr[index] <= arr[right]) {
			marker++;
			if (index > marker) {
				swap(arr[index], arr[marker]);
			}
		}
	}

	QuickSort(arr, marker - 1, left);
	QuickSort(arr, right, marker);
}
int main()
{
	int* array = new int[10]{ 5,9,3,0,1,2,6,0,2,4 };
	int right = 0;
	QuickSort(array, right);
	
}
