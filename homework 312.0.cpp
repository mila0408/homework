

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");


	int min, max; cin >> min >> max;
	srand(time(NULL));
	const int A = 10;
	int array[A];
	for (int i = 0; i < A; i++) {
		array[i] = min + rand() % (max - min + 1);
		cout << array[i] << ' ';
	}
	cout << endl;

	bool flag;
	for (int i = 0; i < A; i++) {
		flag = true;
		for (int j = 0; j < A - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				flag = false;
			}
		}
		if (flag)break;
	}

	for (int i = 0; i < A; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;



}
