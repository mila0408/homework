#include <string>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
const string  PATH = "copy.txt";
void copyFile(string path,int size) {
	ifstream in(path);
	if (in.is_open())
	{
		string str;
		while (getline(in,str))
		{
			if (str.length()<= size)
			{
				ofstream out("text.copy.txt");
				out << str;
			}
		}
	}
}




int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size;
	cout << "Введите число:" << endl;
	cin >> size;
	copyFile(PATH, size);
	


}

