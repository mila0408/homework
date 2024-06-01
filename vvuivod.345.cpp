#include <Windows.h>
#include <iostream>
#include <string>
#define random(min,max) min+rand()%(max - min +1)
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	 int ROW = 4, COLUMN = 4;
	 int** array = new int *[ROW];

	 for (int i = 0; i < ROW; i++)
	 {
		 array[i] = new int[COLUMN];
	 }
	 for (int i = 0; i < ROW; i++) {
		 for (int j = 0; j < COLUMN; j++) {
			 array[i][j] = random(1, 9);
			 cout << array[i][j] << ' ';
		 }
		 cout << endl;

	 }
	 cout << endl;

	// //добавление в  двумерный динамический массив еще один одномерный
	// int* newArray = new int[COLUMN] {0, 1, 2, 3};
	// int** buf = new  int* [ROW + 1];
	// for (int i = 0; i < ROW; i++) {
	//  buf[i] = array[i];
	// }
	// // создание копии массива , который должен был быть добавлен в двумеррный динамический массив
	// buf[ROW] = new int[COLUMN];
	// for (int i = 0; i < COLUMN; i++) {
	//  buf[ROW][i] = newArray[i];
	// }
	// delete[]  array;
	// array = buf;
	// ROW++;


	////  добовление по индексу
	// int index = 2;
	// for (int i = 0; i < index; i++){
	// buf[i] = array[i];
	// }
	// buf[index] = newArray;
	// for (int i = index; i < ROW; i++) {
	// buf[i+1] = array[i];
	// }
	// delete[] array;
	// array = buf;
	// ROW++;

 //    //удаление по индексу
	//  int index = 2;
	// for (int i = 0; i < index; i++) {
	// buf[i] = array[i];
	// }
	// for (int i = index; i < ROW; i++) {
	// buf[i] = array[i+1];
	// }
	// delete[] array[index];
	// delete[] array;
	// array = buf;
	// ROW--;
	  //добовление по индексу ряда и колонки 
	/* int rowIndex = 1;
	 int columnIndex =1;
	 int num = 99;
	 int needSizeColumn = COLUMN + 1;
	 int** def = new int* [ROW];
	 for (int i = 0; i < ROW; i++)
	 {
		 if (i == rowIndex)
		 {
			 def[i] = new int[needSizeColumn];
		 }
		 def[i] = new int[COLUMN];
	 }
	 for (int i = 0; i < ROW; i++)
	 {
		 bool flag = true;
		 for (int j = 0; j < COLUMN; j++)
		 {
			 if (rowIndex == i && columnIndex == j)
			 {
				 def[i][j] = num;
				 flag = false;
			 }
			 else if (flag == false)def[i][j] = array[i][j-1];
			 else def[i][j] = array[i][j];
		 }
	 }
			 
	 delete[] array;
	 array = def;*/
	
	 // удалкнеи по идексу ряда и колонки
	 /* int rowIndex = 1;
	  int columnIndex = 1;
	  int needSizeColumn = COLUMN - 1;
	  int** def = new int* [ROW];
	  for (int i = 0; i < ROW; i++)
	  {
		  if (i == rowIndex)
		  {
			  def[i] = new int[needSizeColumn];
		  }
		  def[i] = new int[COLUMN];
	  } for (int i = 0; i < ROW; i++)
	  {
		  bool flag = true;
		  for (int j = 0; j < COLUMN; j++)
		  {
			  if (rowIndex == i && columnIndex == j)
			  {
				  def[i][j] = array[i][j+1];
				  flag = false;
			  }
			  else if (flag == false)def[i][j] = array[i][j+1];
			  else def[i][j] = array[i][j];
		  }
	  }

	  delete[] array;
	  array = def;*/
     // удаление элемента по значению( по первому вхождению )
     int num = 4;
	 int needSizeColumn = COLUMN - 1;
	 int** def = new int*[ROW];
	 for (int i = 0; i < ROW; i++)
	 {
		 def[i] = new int[COLUMN];
	 }
	 for (int i = 0; i < ROW; i++)
	 {
		 bool flag = true;
		 int count = 0; 
		 for (int j = 0; j < COLUMN; j++)
		 {
			 if (array[i][j] == num && count==0)
			 {
				 def[i][j] = array[i][j + 1];
				 count += 1;
				 flag = false;
			 }
			 else if( flag == false) def[i][j] = array[i][j + 1];
			 else  def[i][j] = array[i][j];
		 }
	 }
	 delete[] array;
	 array = def;
	 //здесь я не понимаю как уменьшить размер column т.к. мы попустили элемень но не удалили его.

	 //универсальное вывидение динамического двухмерного массива
	 // только одна проблема - я не могу понять почему мой ввывод не ввыводит элементы которые находяятся в индексах  больше чем ROW или COLUMN

	 int size1 = _msize(array) / sizeof(array[0]);
	 int size2;

	 for (int i = 0; i < size1; i++) {
		 size2 = _msize(array[0]) / sizeof(array[0][0]);
		 for (int j = 0; j < size2; j++) {
			 cout << array[i][j] << ' ';
		 }
		 cout << endl;
	 }





