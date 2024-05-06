
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    // задание 1
    int a = 10, b = 5;
    int* array = new int[b] {1, 2, 3, 4, 5};
    int* dop = new int[b] {6, 7, 8, 9, 0};
    for (int i = 0; i < 5; i++) {
          array[i]=dop[i+5];
    }
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    //задание 2
    int index = 2;
    int* buf = new int[a];
    for (int i = 0; i < index; i++) {
        buf[i] = array[i];
     }
     for(int i =0;i<b;i++){
         buf[i+index]=dop[i];
     }

    for (int i = 0; i < b-index; i++) {
    buf[i+index+b-1]=array[i+inbex];
    }
    delete[] array;
    array=buf;
    b+=b;


    //задание 3
    int udl = 3;// cin >> udl;
    bool flag = true;
    int* buf = new int[b - 1];
    for (int i = 0; i < b - 1; i++) {
        while (flag = true) {
            if (array[i] != udl)buf[i] == array[i];
            else if (array[i] == udl) flag = false;
        }
        buf[i] == array[i + 1];
    }
    buf == array;
    delete[] array;
    b--;

    for (int i = 0; i < b; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;








}
