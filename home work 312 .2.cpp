

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
     //задание 1

	//int min, max; cin >> min >> max;
	//srand(time(NULL));
	//const int A = 10;
	//int array[A];
	//for (int i = 0; i < 10; i++) {
	//	array[i] = min + rand() % (max - min + 1);
	//	cout << array[i] << ' ';
	//}
	//cout << endl;

	//int maxIndex = array[0], minIndex = array[0];
	//for (int i = 0; i < A; i++) {
	//	if (array[i] > maxIndex)maxIndex = array[i];
	//	else if (array[i] < minIndex)minIndex = array[i];
	//}
	//cout << minIndex <<' ' << maxIndex;

	// задание 2

	//int min, max; cin >> min >> max;
	//srand(time(NULL));
	//const int A = 10;
	//int array[A];
	//for (int i = 0; i < 10; i++) {
	//	array[i] = min + rand() % (max - min + 1);
	//	cout << array[i] << ' ';
	//}
	//cout << endl;
	// 
	//int a,summa=0; cin >> a;
	//for (int i = 0; i < A; i++) {
	//	if (array[i] < a)summa += array[i];
	//}
	//cout << summa;

	//задание 3
	

	//int min, max; cin >> min >> max;
	//srand(time(NULL));
	//const int A = 10;
	//int array[A];
	//for (int i = 0; i < 10; i++) {
	//	array[i] = min + rand() % (max - min + 1);
	//	cout << array[i] << ' ';
	//}
	//cout << endl;

	//

	//int a, b, var = 0,var1 = 0; cin >> a >> b;
	//var = array[a];
	//var1 = array[a];
	//for (int i = a; i > a && i < b; i++) {
	//	if (array[i] > var) {
	//		var = array[i];
	//	}
	//	else if (array[i] < var1) {
	//		var1 = array[i];
	//	}
	//}
	//cout << var<<' ' << var1;
	// не смоглп решить до конца ((

	//задание 4 

	int min, max; cin >> min >> max;
	int a=0, b=1,g=1;
	const int N = 15;
	int array[N]{1,2,6,-2,3,0,57,-9,7,-19,4,28,3,24,-2};
	for (int i = 0; i < 15; i++) {
		if(array[i]<0){
			a += array[i];
		}
		else if(array[i]>min && i<max){
			b = b*array[i];
		}
		else if(array[i] % 2 == 0 ){
			g = g*array[i];
		}
	// доделать 

		
	}

cout << a << ' ' << b <<' ' << g;


























}
