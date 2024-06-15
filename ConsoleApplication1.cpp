#include <iostream>
#include <string> 
#include <fstream>  
#include <Windows.h> 
using namespace std;
int CURRENT_ID = 1;
string PATH = "product.txt";

enum Category {
    Food = 1,
    Cloth,
    Household_products,
    Office

};
struct Product {
    int id;
    string name;
    Category category;
    float price;
    int quantity;
    Product() {}
    Product(int id, string name, Category category, float price, int quantity) :id(id), name(name), category(category),
        price(price), quantity(quantity) {}

};
Category strToCotegory(string str) {
    if (str == "food")return Food;
    else if (str == "cloth")return Cloth;
    else if (str == "household_products")return Household_products;
    else if (str == "office") return Office;

}
struct Shop {
    int size = 0;
    Product* products = new Product[size];
    Shop() {}
    Shop(Product* products, int size) : products(products), size(size) {}
};
//producr cteaetProduct(int id, string name, string category, float price, int quantity) { 
// Product add(id,name,strToCotegory(category),price,quantity); 
// } 
void addProduct(Shop& shop, Product add) {
    Product* def = new Product[shop.size + 1];
    for (int i = 0; i < shop.size; i++)
    {
        def[i] = shop.products[i];
    }
    def[shop.size] = add;
    delete[] shop.products;
    shop.products = def;
    shop.size += 1;
}
void maxId(Product*& pro, int size) {
    int max = pro[0].id;
    for (int i = 0; i < size; i++)
    {
        if (pro[i].id > max)max = pro[i].id;
    }
    CURRENT_ID += max;
}
Product strToProduct(string date) {
    string prDate[5];
    string str = "";
    for (int count = 0, i = 0; i <= date.length(); i++)
    {
        if (date[i] == ';' || i == (date.length()))
        {
            prDate[count++] = str;
            str = "";
        }
        else str += date[i];
    }
    Product p1(stoi(prDate[0]), prDate[1], strToCotegory(prDate[2]), stof(prDate[3]), stoi(prDate[4]));
    return p1;
}
void readFile(Shop& shop) {
    fstream in(PATH);
    if (in.is_open())
    {
        string str;
        while (getline(in, str))
        {
            addProduct(shop, strToProduct(str));
        }
        maxId(shop.products, shop.size);
    }
    in.close();

}
string categoryToStr(Category cat) {
    if (cat == Food)return"food";
    else if (cat == Cloth)return "cloth";
    else if (cat == Household_products)return"household_products";
    else if (cat == Office) return"office";
}
void print(Product prod) {
    cout << "category:" << categoryToStr(prod.category) << endl;
    cout << "id:" << prod.id << endl;
    cout << "name:" << prod.name << endl;
    cout << "prise:" << prod.price << endl;
    cout << "quantity:" << prod.quantity << "\n\n";
}
void show(Shop& shop) {
    for (int i = 0; i < shop.size; i++)
    {
        print(shop.products[i]);
    }
}

void deleteProduct(Shop& shop, int index) {
    Product* def = new Product[shop.size - 1];
    for (int i = 0; i < index; i++)
    {
        def[i] = shop.products[i];
    }
    for (int i = index + 1; i < shop.size; i++)
    {
        def[i] = shop.products[i + 1];
    }
    delete[]shop.products;
    shop.products = def;
    shop.size--;
}
void deleteProductByName(Shop& shop, string name) {
    int index = -1;
    for (int i = 0; i < shop.size; i++)
    {
        if (shop.products[i].name == name)
        {
            index = i;
        }
    }
    if (index != -1)deleteProduct(shop, index);

}
void showCategory(Shop& shop, string category) {
    for (int i = 0; i < shop.size; i++)
    {
        if (shop.products[i].category == strToCotegory(category))
        {
            print(shop.products[i]);
        }
    }
}
void saveInFile(Shop& shop) {
    ofstream out(PATH);
    for (int i = 0; i < shop.size; i++)
    {
        out << shop.products[i].id << ';'
            << shop.products[i].name << ';'
            << categoryToStr(shop.products[i].category) << ';'
            << shop.products[i].price << ';'
            << shop.products[i].quantity<<endl;
    }
}
void changeDatePoduct(Shop& shop, string name) {
    int choice;
    bool flag = true;
    while (flag)
    {
        cin >> choice;
        cout << "Увиичить количество: 1" << endl;
        cout << "Уменьшить количество: 2" << endl;
        cout << "Выйти: 0" << endl;
        switch (choice) {
        case 1: {
            cout << "Введить то количество на которое хотите увеличить :";
            int namP; cin >> namP;
            for (int i = 0; i < shop.size; i++)
            {
                if (namP >= 1 && shop.products[i].name == name)
                {
                    shop.products[i].quantity += namP;
                    print(shop.products[i]);
                }
                else cout << "" << endl;
            }
            break;
        }
        case 2: {
            cout << "";
            int namM; cin >> namM;
            for (int i = 0; i < shop.size; i++)
            {
                if (namM <= shop.products[i].quantity && shop.products[i].name == name)
                {
                    shop.products[i].quantity -= namM;
                    print(shop.products[i]);
                }
            }
        }
        case 0: {
            flag = false;
            break;
        }
        
        default:
            break;
        }

        }

    }

int main(){

    Shop s;
    readFile(s);
    int choice;
    bool work = true;
    while (work)
    {
        cout << "Вывод всех продуктов: 1" << endl;
        cout << "Вывести все продукты по категории: 2" << endl;
        cout << "Добавить продукт в список: 3" << endl;
        cout << "Удалить продукт из списка: 4" << endl;
        cout << "Изменить количество либо цену продукта: 5" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: {
            show(s);
            Sleep(7000);
            system("cls");
            break;
        }
        case 2: {
            string needCategory;
            cout << "Введите каткгорию строго так как при выводе:";
            cin >> needCategory;
            showCategory(s, needCategory);
            Sleep(7000);
            system("cls");
            break;
         }
        case 3: {
            cout << "id;name;category;price;quantity"<<endl;
            cout << "Введите так как указано в примере:";
            string add; cin >> add;
            addProduct(s, strToProduct(add));
            show(s);
            Sleep(7000);
            system("cls");
            break;
        }
        case 4: {
            cout << "Введите имя продукта который хотите удалить:";
            string name; cin >> name;
            deleteProductByName(s, name);
            show(s);
            Sleep(7000);
            system("cls");
            break;
        }
        case 5: {
            string change;
            cout << "Ввудите имя продукта количество которого вы хотите изменить: "; cin >> change;
            changeDatePoduct(s, change);
            Sleep(7000);
            system("cls");
            break;
        }
        case 0: {
            work = false;
            break;
        }

        default:
            break;
        }
    }
    
    
    saveInFile(s);
}