﻿

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	int* array = new int [10]{1,2,3,4,5,6,7,8,9,0};
	for (int i = 0; i < 10; i++) {
		cout << array[i] << ' ';
	}
}

