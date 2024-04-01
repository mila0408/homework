
#include <iostream>
using namespace std;

// задание 1 (выяснить является ли число счастливым)
void luckynumber(int num) {
	int a = 0,summa1=0,summa2=0;
	for (int i = 0; i < 6; i++) {
		a = num % 10;
		num = num / 10;
		if (i <= 2)summa1 += a;
		else summa2 += a;
	}
	if (summa1 == summa2) cout << "this is a lucky number"; 
	else cout << "this isn't a lucky number"; 
}
// задание 2 (алгоритм линейного поиска заданного ключа )
void keysearch(int arr[], int key) {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (arr[i] == key) count++;
	}
	if (count != 0)cout << count << " matches found";
	else cout << " no discrepancies found";
}



int main()
{
	//1
	setlocale(LC_ALL, "rus");
	int num; cin >> num;
	luckynumber(num);

	//2
	const int A = 10;
	int array[A];
	int key; cin >>key;
	srand(time(NULL));
	for (int i = 0; i < A; i++) {
		array[i] = rand() % 10;
		cout << array[i]<<' ';
	}
	cout << endl;
	keysearch(array, key);
}
