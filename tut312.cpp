#include <iostream>

using namespace std;
//задание 1 ( возведение в степень)
int degree(int a, int b) {
	int v = a;
	for (int i = 0; i < b-1; i++){
		a *= v;
	}
	return a;
}
//заданеи 2 (получение суммы диапазона ( я считаю не включительно самих g,h))
int summa(int g, int h) {
	int summa=0;
	for (int i = g+1; i < h; i++) {
		summa += i;
	}
	return summa;
}

int main()
{
	setlocale(LC_ALL, "rus");
	//1
	/*cout << " введите сначала число, а после степень"<< endl;
	int a, b; cin >> a >> b;
	cout << degree(a, b);*/

	//2
	cout << " сначала введите меньшее число, а после большее" << endl;
	int g, h; cin >> g >> h;
	cout << summa(g, h);












}

