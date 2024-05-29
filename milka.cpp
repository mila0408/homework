#include <iostream>
#include <string>
#include <Windows.h>
#include<fstream>
#define random(min,max) min+rand()%(max - min +1)
using namespace std;

struct Student {
    string name;
    int age;
    float avg;
    int id;
    Student() {};
    Student(string nam, int a, float avg, int id) : name(nam), age(a), avg(avg), id(id) {};
};
void print(Student s) {
    cout << "name:" << s.name << endl << "age:" << s.age << endl << "avg:" << s.avg <<endl<<"id:"<<s.id<< "\n\n";
}
void allStudents(Student* stu, int size) {
    
    for (int i = 0; i < size; i++)
    {
        print(stu[i]);
    }
}
void avg(Student* stu, int size) {
    int avg;
    for (int i = 0; i < size; i++)
    {
        if (stu[i - 1].avg < stu[i].avg) avg = i;
    }
    print(stu[avg]);
}
int idFind(int id, Student* stu, int size) {
    for (int i = 0; i < size; i++)
    {
        if (id == stu[i].id) return i;
    }
}

void deleteId(int id, Student*& stu, int& size) {
    Student* def = new Student[size--];
   int a = idFind(id, stu, size);
    for (int i = 0; i < a; i++)
    {
        def[i] = stu[i];
    }
    for ( int i = a +1; i < size; i++)
    {
        def[i- 1] = stu[i];
    }
    delete[] stu;
    stu = def;
    cout<< "Успешно удалено!" <<"/n/n";
}
void correctionOfData(Student*& stu, int size, string newName, int needId) {
     int i = idFind(needId, stu, size);
     stu[i].name = newName;
     cout<<"Даные успешно измененны" << endl;
   
}
void correctionOfData(Student*& stu, int size, int newID, int needId) {
    int i = idFind(needId, stu, size);
    stu[i].id = newID;
    cout << "Даные успешно измененны" << endl;
}
void correctionOfData(Student*& stu, int size, float newAVG, int needId) {
    int i = idFind(needId, stu, size);
    stu[i].avg = newAVG;
    cout << "Даные успешно измененны" << endl;
}
void correctionOfData(Student*& stu, int size, int newAge,int needId) {
    int i = idFind(needId, stu, size);
    stu[i].age = newAge;
    cout << "Даные успешно измененны" << endl;
}

void addStudent(string name, int age, float avg, int id,int& size,Student*& stu) {
    Student* def = new Student[size+1];
    Student s4(name, age, avg, id);
    for (int i = 0; i < size; i++)
    {
        def[i] = stu[i];
    }
    def[size] = s4;
    delete[] stu;
    stu = def;
    size++;
    cout << "Успешно добавленно!";
 }
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");


    int size = 3;
    Student s1("Bella", 16, 4.52, 123456789);
    Student s2("Jacob", 15, 3.12, 987654321);
    Student s3("Edvard", 717, 5.00, 192837465);

    Student* students = new Student[size]{ s1,s2,s3 };
    int choice;
   
    while (true) {
        cout << "Вывести всех студентов : 1" << endl;
        cout << "Удаление студента по ID: 2" << endl;
        cout << "Обновить двнные о студентах: 3" << endl;
        cout << "Добовление нового судента : 4" << endl;
        cout << "Выбеит дейтвие: ";
        cin >> choice;
        switch (choice) {

        case 1:
            allStudents(students, size);
            Sleep(7000);
            system("cls");
            break;

        case 2: {
            allStudents(students, size);
            cout << "Выберите студента и введите его id:" << endl;
            int num; cin >> num;
            deleteId(num, students, size);
            allStudents(students, size);
            Sleep(10000);
            system("cls");
            break;


        }
        case 3: {
            int needid;
            int newID;
            string newName;
            float newAVG;
            int newAge;
            string whateWeNeed;
            cout << "Ввудите id студента чьи данные в хотие изменить " << endl;
            cin >> needid;
            cout << "Выберите то,что выхтите изменить и ввдите строго по примеру:" << endl;
            cout << "(возраст/средн.бл/имя/айди)" << endl;
            cin >> whateWeNeed;
            if (whateWeNeed == "имя")
            {
                cout << "Ввудите новое имя:" << endl;
                cin >> newName;
                correctionOfData(students, size, newName, needid);
                print(students[idFind(needid, students, size)]);
            }
            else if (whateWeNeed == "возраст") {
                cout << "Ввудите новый возраст:" << endl;
                cin >> newAge;
                correctionOfData(students, size, newAge, needid);
                print(students[idFind(needid, students, size)]);
            }
            else if (whateWeNeed == "средн.бл") {
                cout << "Ввудите новый сред.бл:" << endl;
                cin >> newAVG;
                correctionOfData(students, size, newAVG, needid);
                print(students[idFind(needid, students, size)]);
            }
            else if (whateWeNeed == "айди") {
                cout << "Ввудите новй айди:" << endl;
                cin >> newID;
                correctionOfData(students, size, newID, needid);
                print(students[idFind(needid, students, size)]);
            }
            else cout << "ошибка!" << endl;
            Sleep(10000);
            system("cls");
            break;
        }
        case 4: {
            cout << "Введите AVG: " << endl;
            float AVG; cin >> AVG;
            cout << "Введите имя " << endl;
            string name; cin >> name;
            cout << "Введите возраст " << endl;
            int age; cin >> age;
            cout << "Введите ID  " << endl;
            int id; cin >> id;
            addStudent(name, age, AVG, id, size, students);
            allStudents(students, size);
            Sleep(10000);
            system("cls");
            break;
        }


        default:
            break;
        }
    }
}
