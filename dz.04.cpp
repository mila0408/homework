

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	// алгоритм сортировки вставками 

	int min, max; cin >> min >> max;
	srand(time(NULL));
	const int A = 10;
	int array[A];
	for (int i = 0; i < A; i++) {
		array[i] = min + rand() % (max - min + 1);
		cout << array[i] << ' ';
	}
	cout << endl;


	int  buf = 0;
	for (int i =1; i < A; i++) {
		if (array[i] < array[i-1]) {
			buf = array[i];
			for (int j = i; j >= 0; j--) {
				if (buf < array[j-1]) array[j] = array[j - 1];
				else {
				array[j] = buf;
				break;
				}
					
				
			}
		}
		
	}



	for (int i = 0; i < A; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;











































}

