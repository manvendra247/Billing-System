#include <bits/stdc++.h>
using namespace std;

class Shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu()
    {
    m:
        int choice;
        string email;
        string password;
        cout << "\t\t\t\t_______________________________________________\n";
        cout << "\t\t\t\t                                               \n";
        cout << "\t\t\t\t            Supermarket Main Menu              \n";
        cout << "\t\t\t\t                                               \n";
        cout << "\t\t\t\t_______________________________________________\n";
        cout << "\t\t\t\t                                               \n";
        cout << "\t\t\t\t|  1) Administrator   |" << endl;
        cout << "\t\t\t\t|                     |" << endl;
        cout << "\t\t\t\t|  2) Buyer           |" << endl;
        cout << "\t\t\t\t|                     |" << endl;
        cout << "\t\t\t\t|  3) Exit            |" << endl;
        cout << "\t\t\t\t|                     |" << endl;
        cout << "\t\t\t\t Please select: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\t\t\t Please Login \n";
            cout << "\t\t\t Enter Email \n";
            cin >> email;
            cout << "\t\t\t Password \n";
            cin >> password;
            if (email == "admin@gmail.com" && password == "admin@123")
            {
                administrator();
            }
            else
                cout << "Invalid email/password" << endl;
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Please Select from the given options only" << endl;
            break;
        }
        goto m;
    }
    void administrator()
    {
    m:
        int choice;
        cout << "\n\n\n\t\t\t Administrator Menu";
        cout << "\n\t\t\t|______1) Add the product_______|";
        cout << "\n\t\t\t|";
        cout << "\n\t\t\t|______2) Modify the product____|";
        cout << "\n\t\t\t|";
        cout << "\n\t\t\t|______3) Delete the product____|";
        cout << "\n\t\t\t|";
        cout << "\n\t\t\t|______4) Back to Main Menu ____|";
        cout << "\n\n\t Please Enter your choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;

        default:
            cout << "Invalid choice " << endl;
            break;
        }
        goto m;
    }
    void buyer()
    {
    m:
        int choice;
        cout << "\t\t\t    Buyer  \n";
        cout << "\t\t\t________________\n";
        cout << "                 \n";
        cout << "\t\t\t 1) Buy Product \n";
        cout << "                      \n";
        cout << "\t\t\t 2) Go back     \n";
        cout << "\t\t\t Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;

        default:
            cout << "invalid choice";
            break;
        }
        goto m;
    }
    void add()
    {
    m:
        fstream data; // file handling operation
        int c;
        int token = 0;
        float p, d;
        string n;
        cout << "\n\n\t\t\t Add new procuct";
        cout << "\n\n\t Product code of the product ";
        cin >> pcode;
        cout << "\n\n\t Name of the product ";
        cin >> pname;
        cout << "\n\n\t Price of the product ";
        cin >> price;
        cout << "\n\n\t Discount on product";
        cin >> dis;

        data.open("database.txt", ios::in);
        if (!data)
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
        else
        {
            data >> c >> n >> p >> d;
            while (!data.eof())
            {
                if (c == pcode)
                    token++;
                data >> c >> n >> p >> d;
            }
            data.close();
        }
        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
        cout << "\n\n\t\t Record inserted |";
    }
    void edit()
    {
        fstream data, data1;
        int pkey, token = 0, c;
        float p, d;
        string n;
        cout << "\n\t\t\t Modify the record";
        cout << "\n\t\t\t Product code :";
        cin >> pkey;
        data.open("database.txt", ios::in);
        if (!data)
            cout << "\n\n File doesn't exist! ";
        else
        {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pkey == pcode)
                {
                    cout << "\n\t\t Product new code :";
                    cin >> c;
                    cout << "\n\t\t Name of the product :";
                    cin >> n;
                    cout << "\n\t\t Price :";
                    cin >> p;
                    cout << "\n\t\t Discount :";
                    cin >> d;
                    data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                    cout << "\n\n\t\t Record edited";
                }
                else
                {
                    data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt", "database.txt");

            if (token == 0)
            {
                cout << "\n\n Record not found! " << endl;
            }
        }
    }
    void rem()
    {
        fstream data, data1;
        int pkey;
        int token = 0;
        cout << "\n\n\t Delete product";
        cout << "\n\n\t Product code :";
        cin >> pkey;
        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "\n\t file doesn't exist! " << endl;
        }
        else
        {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == pkey)
                {
                    cout << "\n\n\t Product deleted successfully! " << endl;
                    token++;
                }
                else
                {
                    data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (token == 0)
            {
                cout << "\n\n Record not found" << endl;
            }
        }
    }
    void list()
    {
        fstream data;
        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "\n\t Your list is empty! " << endl;
        }
        else
        {
            cout << "\n\n|_______________________________________________________\n";
            cout << "proNo\t\tName\t\tPrice\n";
            cout << "\n\n|_______________________________________________________\n";
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    void receipt()
    {
    m:
        fstream data;
        vector<int> arrc(100, 0);
        vector<int> arrq(100, 0);
        char choice;
        int c = 0;
        float amount = 0, dis = 0, total = 0;
        cout << "\n\n\t\t\t RECEIPT ";
        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "\n\n Empty database";
        }
        else
        {
            data.close();
            list();
            cout << "\n______________________________________________\n";
            cout << "\n|                                             \n";
            cout << "\n      Please place the order                  \n";
            cout << "\n|                                             \n";
            cout << "\n______________________________________________\n";
            do
            {
                cout << "\n\n Enter Product code :";
                cin >> arrc[c];
                cout << "\n\n Enter Product quantity :";
                cin >> arrq[c];
                for (int i = 0; i < c; i++)
                {
                    if (arrc[c] == arrc[i])
                    {
                        cout << "\n\n Duplicate product code. Please try again!";
                        goto m;
                    }
                }
                c++;
                cout << "\n\n Do you want to buy another product? if yes then press y else n";
                cin >> choice;
            } while (choice == 'y');

            cout << "\n\n________________________Receipt__________________\n";
            cout << "\nProduct No\t  Product Name\t  Product Quantity \t ";

            for (int i = 0; i < c; i++)
            {
                data.open("database.txt", ios::in);
                data >> pcode >> pname >> price >> dis;
                while (!data.eof())
                {
                    if (pcode == arrc[i])
                    {
                        amount = price * arrq[i];
                        dis = amount - amount * dis / 100;
                        total = amount + dis;
                        cout << "\n"
                             << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << dis;
                    }
                    data >> pcode >> pname >> price >> dis;
                }
            }
            data.close();
        }
        cout << "\n\n__________________________________________________";
        cout << "\n\t Total Amount: " << total << endl;
    }
};
int main()
{
    Shopping s;
    s.menu();
    return 0;
}