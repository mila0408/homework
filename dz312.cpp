

#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
  
    //задание  1 

    int a,d = 0; cin >> a;
    for (a; a <= 500; a++) {
        d += a;
    }
    cout << d;

    // задание 2

    int x, y,c=0; cin >> x >> y;
    c = x;
    for (int i = 0; i < y-1; i++) {
        x = x*c;
    }
    cout << x;

    // задание 3

    int a = 0,i=0;
    for ( i ; i >= 1 && i <= 1000; i++) {
        a+=i;
    }
    cout << a / i;


    // задние 4 

    int a, b =1 ; cin >> a;

    if (a <= 20 && a >= 1) {
        for (a; a <= 20; a++) {
            b = b * a;
        }
       
    }
    cout << b;

    // задание 5 

    int k; cin >> k;
    for (int i = 1; i <= 10; i++) {
        cout << k << '*' << i<<'=' << i * k<< endl;
    }

















}


