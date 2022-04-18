#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <string.h>
#include <limits>
using namespace std;

bool loginSystem();
void mainMenu();
void case1();
void case2();
void case3();
class Property
{
protected:
    int area;
    int pID;
    int price;
    string address;
    int no_of_bedRooms;
    int property_choice;

public:
    Property()
    {
        cout << "\n\n\n\t\t\t\t___________________Property MANAGEMENT SCREEN!!!___________________";
        cout << "\n\n\t\t\t\t1) Add Property";
        cout << "\n\n\t\t\t\t2) ALL available Properties";
        cout << "\n\n\t\t\t\t3) Search Properties";
        cout << "\n\n\t\t\t\t4) Modify Property";
        cout << "\n\n\t\t\t\t5) Delete Property";
        cout << "\n\n\t\t\t\t6) Sold Properties";
        cout << "\n\n\t\t\t\t7) Main Menu";
        cout << "\n\n\t\tEnter Choice:";
        cin >> property_choice;
    }

    int propertyChoice()
    {
        return property_choice;
    }
    void addProperty()
    {
        int iID;
        cout << "\n\n\t\tEnter Property ID:";
        cin >> pID;
        iID = pID;
        fstream file1;
        file1.open("Property.txt");
        if (file1)
        {
            int tempID;
            int count = 0;
            tempID = pID;
            // file1.open("Property.txt");
            while (!file1.eof())
            {
                file1 >> pID;
                file1 >> area;
                file1 >> price;
                file1 >> no_of_bedRooms;
                file1.ignore();
                getline(file1, address);
                if (pID == tempID)
                {
                    count++;
                }
            }
            file1.close();
            if (count > 0)
            {
                cout << "Entered ID already exist";
                cout << "\n";
                system("pause");
                system("CLS");
                case1();
            }
        }

        // pID++;
        cout << "\n\n\t\tEnter Property Area:";
        cin >> area;
        cout << "\n\n\t\tEnter Property Price:";
        cin >> price;
        cout << "\n\n\t\tEnter No of Bed Rooms:";
        cin >> no_of_bedRooms;
        cout << "\n\n\t\tEnter Property Address:";
        // cin>>address;
        cin.get();
        getline(cin, address);

        fstream file;
        file.open("Property.txt", ios::out | ios::app);
        file << "\n"
             << iID << " ";
        file << area << " ";
        file << price << " ";
        file << no_of_bedRooms << " ";
        file << address;
        file.close();
        cout << "\n\n\t\tRecord Inserted successfully!";
        Sleep(3000);
        system("CLS");
        case1();
    }
    void allProperties()
    {
        cout << "All the Properties that are in our Record";
        fstream file;
        file.open("Property.txt");

        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case1();
        }
        else
        {
            while (!file.eof())
            {
                file >> pID;
                file >> area;
                file >> price;
                file >> no_of_bedRooms;
                file.ignore();
                getline(file, address);
                // file>>address;
                cout << endl
                     << "Property ID=" << pID << " Property Area=" << area << " Property Price=" << price << " No. of bed rooms=" << no_of_bedRooms << " Property Address=" << address;
            }
            file.close();
            cout << "\n";
            system("pause");
            system("CLS");
            case1();
        }
    }
    void searchProperties()
    {
        int sID, count = 0;
        cout << "Enter Property id that you want to search" << endl;
        cin >> sID;
        fstream file;
        file.open("Property.txt");
        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case1();
        }
        while (!file.eof())
        {
            file >> pID;
            file >> area;
            file >> price;
            file >> no_of_bedRooms;
            file.ignore();
            getline(file, address);
            if (pID == sID)
            {
                count++;
                cout << endl
                     << "Property ID=" << pID << " Property Area=" << area << " Property Price=" << price << " No. of bed rooms=" << no_of_bedRooms << " Property Address=" << address;
            }
        }
        if (count == 0)
        {
            cout << "Entered ID does not exist ";
        }
        file.close();
        cout << "\n";
        system("pause");
        system("CLS");
        case1();
    }
    void modifyProperties()
    {
        int dID, count = 0;
        cout << "Enter ID that you want to Modify" << endl;
        cin >> dID;
        fstream file1;
        file1.open("Property.txt");
        if (file1)
        {
            while (!file1.eof())
            {
                file1 >> pID;
                file1 >> area;
                file1 >> price;
                file1 >> no_of_bedRooms;
                file1.ignore();
                getline(file1, address);
                if (pID == dID)
                {
                    count++;
                }
            }
            file1.close();
            if (count == 0)
            {
                cout << "Entered ID does not exist";
                cout << "\n";
                system("pause");
                system("CLS");
                case1();
            }
        }
        int Darea;
        int DpID;
        int Dprice;
        string Daddress;
        int Dno_of_bedRooms;
        int Dproperty_choice;

        // cout << "\n\n\t\tEnter Property ID:";
        // cin >> DpID;
        DpID = dID;
        cout << "\n\n\t\tEnter Property Area:";
        cin >> Darea;
        cout << "\n\n\t\tEnter Property Price:";
        cin >> Dprice;
        cout << "\n\n\t\tEnter No of Bed Rooms:";
        cin >> Dno_of_bedRooms;
        cout << "\n\n\t\tEnter Property Address:";
        // cin>>address;
        cin.get();
        getline(cin, Daddress);

        fstream temp;
        temp.open("temp.txt", ios::app | ios::out);
        fstream file;
        file.open("Property.txt");
        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case1();
        }

        while (!file.eof())
        {
            file >> pID;
            file >> area;
            file >> price;
            file >> no_of_bedRooms;
            file.ignore();
            getline(file, address);

            if (pID != dID)
            {

                temp << "\n"
                     << pID << " ";
                temp << area << " ";
                temp << price << " ";
                temp << no_of_bedRooms << " ";
                temp << address;
            }
            else
            {

                temp << "\n"
                     << DpID << " ";
                temp << Darea << " ";
                temp << Dprice << " ";
                temp << Dno_of_bedRooms << " ";
                temp << Daddress;
            }
        }

        file.close();
        temp.close();
        remove("Property.txt");

        rename("temp.txt", "Property.txt");
        cout << "\n\n\t\tRecord updated successfully!";
        Sleep(3000);
        system("CLS");
        case1();
    }
    void deleteProperties()
    {
        int dID, count = 0;
        cout << "Enter ID that you want to delete" << endl;
        cin >> dID;
        fstream file1;
        file1.open("Property.txt");
        if (file1)
        {
            while (!file1.eof())
            {
                file1 >> pID;
                file1 >> area;
                file1 >> price;
                file1 >> no_of_bedRooms;
                file1.ignore();
                getline(file1, address);
                if (pID == dID)
                {
                    count++;
                }
            }
            file1.close();
            if (count == 0)
            {
                cout << "Entered ID does not exist";
                cout << "\n";
                system("pause");
                system("CLS");
                case1();
            }
        }
        fstream temp;
        temp.open("temp.txt", ios::app | ios::out);
        fstream file;
        file.open("Property.txt");
        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case1();
        }

        while (!file.eof())
        {
            file >> pID;
            file >> area;
            file >> price;
            file >> no_of_bedRooms;
            file.ignore();
            getline(file, address);

            if (pID != dID)
            {

                temp << "\n"
                     << pID << " ";
                temp << area << " ";
                temp << price << " ";
                temp << no_of_bedRooms << " ";
                temp << address;
            }
        }
        file.close();
        temp.close();
        remove("Property.txt");
        rename("temp.txt", "Property.txt");
        cout << "\n\n\t\tRecord Deleted successfully!";
        Sleep(3000);
        system("CLS");
        case1();
    }
    void SoldProperties()
    {
        cout << "All the Properties that are in our Record";
        fstream file;
        file.open("SoldProperty.txt");

        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case1();
        }
        else
        {
            while (!file.eof())
            {
                file >> pID;
                file >> area;
                file >> price;
                file >> no_of_bedRooms;
                file.ignore();
                getline(file, address);
                // file>>address;
                cout << endl
                     << "Property ID=" << pID << " Property Area=" << area << " Property Price=" << price << " No. of bed rooms=" << no_of_bedRooms << " Property Address=" << address;
            }
            file.close();
            cout << "\n";
            system("pause");
            system("CLS");
            case1();
        }
    }
};
class Customer
{
protected:
    string cName;
    string phone;
    string address;
    string email;
    int cID;
    int customer_choice;

public:
    Customer()
    {
        cout << "\n\n\n\t\t\t\t___________________Property MANAGEMENT SCREEN!!!___________________";
        cout << "\n\n\t\t\t\t1) Add Customer";
        cout << "\n\n\t\t\t\t2) ALL Customers";
        cout << "\n\n\t\t\t\t3) Search Customer";
        cout << "\n\n\t\t\t\t4) Delete Customer";
        cout << "\n\n\t\t\t\t5) Main Menu";
        cout << "\n\n\t\tEnter Choice:";
        cin >> customer_choice;
    }

    int CustomerChoice()
    {
        return customer_choice;
    }
    void addCustomer()
    {
        int nID, pID, pID1, area, area1, price, price1, no_of_bedRooms, no_of_bedRooms1, count = 0;
        string paddress, paddress1;
        int iID;
        cout << "\n\n\t\tEnter Customer ID:";
        cin >> cID;
        iID = cID;
        fstream file1;
        file1.open("Customer.txt");
        if (file1)
        {
            int tempID;
            int count1 = 0;
            tempID = cID;
            // file1.open("Property.txt");
            while (!file1.eof())
            {
                file1 >> cID;
                file1 >> cName;
                // file1.ignore();
                // getline(file1, cName);
                file1 >> phone;
                file1 >> email;
                file1 >> address;
                file1 >> pID;
                file1 >> area;
                file1 >> price;
                file1 >> no_of_bedRooms;
                file1.ignore();
                getline(file1, paddress);

                if (cID == tempID)
                {
                    count1++;
                }
            }
            file1.close();
            if (count1 > 0)
            {
                cout << "Entered ID already exist";
                cout << "\n";
                system("pause");
                system("CLS");
                case2();
            }
        }

        cout << "Enter sold property ID";
        cin >> nID;
        fstream file2;
        file2.open("Property.txt");
        while (!file2.eof())
        {
            file2 >> pID;
            file2 >> area;
            file2 >> price;
            file2 >> no_of_bedRooms;
            file2.ignore();
            getline(file2, paddress);
            if (pID == nID)
            {
                count++;
                pID1 = pID;
                area1 = area;
                price1 = price;
                no_of_bedRooms1 = no_of_bedRooms;
                paddress1 = paddress;
                fstream file3;
                file3.open("SoldProperty.txt", ios::out | ios::app);
                file3 << "\n"
                      << pID << " ";
                file3 << area << " ";
                file3 << price << " ";
                file3 << no_of_bedRooms << " ";
                file3 << paddress;
                file3.close();
            }
        }
        //   cout<<pID1<<area1<<price1<<no_of_bedRooms1<<paddress1;
        file2.close();
        if (count == 0)
        {
            cout << "Entered property ID does no exist";
            cout << "\n";
            system("pause");
            system("CLS");
            case2();
        }
        else
        {
            fstream temp;
            temp.open("temp.txt", ios::app | ios::out);
            fstream file;
            file.open("Property.txt");
            if (!file)
            {
                cout << "\n\n\t\tFile Does not Exist!!!";
                Sleep(2000);
                system("CLS");
                file.close();
                case1();
            }

            while (!file.eof())
            {
                file >> pID;
                file >> area;
                file >> price;
                file >> no_of_bedRooms;
                file.ignore();
                getline(file, paddress);

                if (pID != nID)
                {

                    temp << "\n"
                         << pID << " ";
                    temp << area << " ";
                    temp << price << " ";
                    temp << no_of_bedRooms << " ";
                    temp << paddress;
                }
            }

            file.close();
            temp.close();
            remove("Property.txt");

            rename("temp.txt", "Property.txt");
            cout << "\n\n\t\tRecord updated successfully!";
        }

        cout << "\n\n\t\tEnter Customer Name:";

        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> cName;
        // cin.get();
        // getline(cin, cName);
        cout << "\n\n\t\tEnter Customer Phone Number:";
        cin >> phone;
        cout << "\n\n\t\tEnter Customer E-mail Address:";
        cin >> email;
        cout << "\n\n\t\tEnter Customer Address:";
        cin >> address;

        fstream file;
        file.open("Customer.txt", ios::out | ios::app);
        file << "\n"
             << iID << " ";
        file << cName << " ";
        file << phone << " ";
        file << email << " ";
        file << address << " ";
        file << pID1 << " ";
        file << area1 << " ";
        file << price1 << " ";
        file << no_of_bedRooms1 << " ";
        file << paddress1;
        file.close();
        cout << "\n\n\t\tRecord Inserted successfully!";
        Sleep(3000);
        system("CLS");
        case2();
    }
    void allCustomer()
    {
        int nID, pID, pID1, area, area1, price, price1, no_of_bedRooms, no_of_bedRooms1;
        string paddress, paddress1;
        cout << "All the Customers that are in our Record";
        fstream file;
        file.open("Customer.txt");

        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case2();
        }
        else
        {
            while (!file.eof())
            {

                file >> cID;
                file >> cName;
                // file1.ignore();
                // getline(file1, cName);
                file >> phone;
                file >> email;
                file >> address;
                file >> pID;
                file >> area;
                file >> price;
                file >> no_of_bedRooms;
                file.ignore();
                getline(file, paddress);
                cout << endl
                     << "Customer ID= " << cID << " Customer Name= " << cName << " Customer Phone Number = " << phone
                     << " Customer E-Mail Address= " << email << " Customer Address=" << address << endl
                     << "Sold Property ID "
                     << pID << " Area of Property " << area << " Property Price " << price << " NO of Bed Rooms " << no_of_bedRooms
                     << "Property Address " << paddress;
            }
            file.close();
            cout << "\n";
            system("pause");
            system("CLS");
            case2();
        }
    }
    void deleteCustomer()
    {
        int iID, pID, pID1, area, area1, price, price1, no_of_bedRooms, no_of_bedRooms1;
        string paddress, paddress1;
        int sID, count = 0;
        cout << "Enter Customer id that you want to Delete" << endl;
        cin >> sID;
        fstream file1;
        file1.open("Customer.txt");
        if (file1)
        {

            int count1 = 0;

            // file1.open("Property.txt");
            while (!file1.eof())
            {
                file1 >> cID;
                file1 >> cName;
                // file1.ignore();
                // getline(file1, cName);
                file1 >> phone;
                file1 >> email;
                file1 >> address;
                file1 >> pID;
                file1 >> area;
                file1 >> price;
                file1 >> no_of_bedRooms;
                file1.ignore();
                getline(file1, paddress);

                if (cID == sID)
                {
                    count1++;
                }
            }
            file1.close();
            if (count1 == 0)
            {
                cout << "Entered ID does not exist";
                cout << "\n";
                system("pause");
                system("CLS");
                case2();
            }
        }

        fstream tmp;
        tmp.open("tmp.txt", ios::out | ios::app);
        fstream file;
        file.open("Customer.txt");
        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case1();
        }
        while (!file.eof())
        {
            file >> cID;
            file >> cName;
            // file1.ignore();
            // getline(file1, cName);
            file >> phone;
            file >> email;
            file >> address;
            file >> pID;
            file >> area;
            file >> price;
            file >> no_of_bedRooms;
            file.ignore();
            getline(file, paddress);
            if (sID != cID)
            {
                // count++;
                tmp << "\n"
                    << cID << " ";
                tmp << cName << " ";
                tmp << phone << " ";
                tmp << email << " ";
                tmp << address << " ";
                tmp << pID << " ";
                tmp << area << " ";
                tmp << price << " ";
                tmp << no_of_bedRooms << " ";
                tmp << paddress;
            }
        }

        file.close();
        tmp.close();
        remove("Customer.txt");
        rename("tmp.txt", "Customer.txt");
        cout << "\n";
        system("pause");
        system("CLS");
        case2();
    }
    void searchCustomer()
    {
        int nID, pID, pID1, area, area1, price, price1, no_of_bedRooms, no_of_bedRooms1, count = 0;
        string paddress, paddress1;
        cout << "Enter Property ID that you want to search ";
        cin >> nID;
        fstream file;
        file.open("Customer.txt");

        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case2();
        }
        else
        {
            while (!file.eof())
            {

                file >> cID;
                file >> cName;
                // file1.ignore();
                // getline(file1, cName);
                file >> phone;
                file >> email;
                file >> address;
                file >> pID;
                file >> area;
                file >> price;
                file >> no_of_bedRooms;
                file.ignore();
                getline(file, paddress);
                if (cID == nID)
                {
                    count++;
                    cout << endl
                         << "Customer ID= " << cID << " Customer Name= " << cName << " Customer Phone Number = " << phone
                         << " Customer E-Mail Address= " << email << " Customer Address=" << address << endl
                         << "Sold Property ID "
                         << pID << " Area of Property " << area << " Property Price " << price << " NO of Bed Rooms " << no_of_bedRooms
                         << "Property Address " << paddress;
                }
            }
            if (count == 0)
            {
                cout << "Entered ID does not exist ";
            }
            file.close();
            cout << "\n";
            system("pause");
            system("CLS");
            case2();
        }
    }
};
class Bill : public Customer
{
protected:
    int pid;
    int bill;
    int discount;
    int cid;
    int bill_choice;
public:
    Bill()
    {
        cout << "\n\n\n\t\t\t\t___________________Bill MANAGEMENT SCREEN!!!___________________";
        cout << "\n\n\t\t\t\t1) Add Bill";
        cout << "\n\n\t\t\t\t2) ALL Bills";
        cout << "\n\n\t\t\t\t3) Search Customer";
        cout << "\n\n\t\t\t\t4) Delete Customer";
        cout << "\n\n\t\t\t\t5) Main Menu";
        cout << "\n\n\t\tEnter Choice:";
        cin >> bill_choice;
    }

    int billChoice()
    {
        return bill_choice;
    }
    void addBill(){
        
        int nID, pID, pID1, area, area1, price, price1, no_of_bedRooms, no_of_bedRooms1, count = 0;
        string paddress, paddress1;
        cout << "Enter Property ID that to search Bill";
        cin >> nID;
        fstream file;
        file.open("Customer.txt");

        if (!file)
        {
            cout << "\n\n\t\tFile Does not Exist!!!";
            Sleep(2000);
            system("CLS");
            file.close();
            case2();
        }
        else
        {
            while (!file.eof())
            {

                file >> cID;
                file >> cName;
                // file1.ignore();
                // getline(file1, cName);
                file >> phone;
                file >> email;
                file >> address;
                file >> pID;
                file >> area;
                file >> price;
                file >> no_of_bedRooms;
                file.ignore();
                getline(file, paddress);
                if (cID == nID)
                {
                    count++;
                    cout << endl
                         << "Customer ID= " << cID << " Customer Name= " << cName <<"Prperty Price"<< price;
                }
            }
            if (count == 0)
            {
                cout << "Entered ID does not exist ";
            }
            file.close();
            cout << "\n";
            system("pause");
            system("CLS");
            case2();
        }
    }
};
void case1()
{
    int innerChoice;
    Property p1;
    innerChoice = p1.propertyChoice();
    if (innerChoice == 1)
    {
        p1.addProperty();
    }
    else if (innerChoice == 2)
    {
        p1.allProperties();
    }
    else if (innerChoice == 3)
    {
        p1.searchProperties();
    }
    else if (innerChoice == 4)
    {
        p1.modifyProperties();
    }
    else if (innerChoice == 5)
    {
        p1.deleteProperties();
    }
    else if (innerChoice == 6)
    {
        p1.SoldProperties();
    }
    else if (innerChoice == 7)
    {
        mainMenu();
    }

    else
    {
        cout << "\n\n\t\tInvalid Choice!!!!";
        system("CLS");
        case1();
    }
}
void case2()
{
    int innerChoice;
    Customer c1;
    innerChoice = c1.CustomerChoice();
    if (innerChoice == 1)
    {
        c1.addCustomer();
    }
    if (innerChoice == 2)
    {
        c1.allCustomer();
    }
    if (innerChoice == 3)
    {
        c1.searchCustomer();
    }
    if (innerChoice == 4)
    {
        c1.deleteCustomer();
    }
    if (innerChoice == 5)
    {
        mainMenu();
    }
    else
    {
        {
            cout << "\n\n\t\tInvalid Choice!!!!";
            system("CLS");
            case2();
        }
    }
}
void case3(){
    int innerChoice;
    Bill b1;
    innerChoice=b1.billChoice();
    if (innerChoice==1)
    {
        b1.addBill();
    }
    
}
void mainMenu()
{
    // bool isLoggedin = loginSystem();
    // if (isLoggedin)
    // {
    int mainChoice, innerChoice;
    system("CLS");
    cout << "\n\n\n\t\t\t\t___________________Real Estate MANAGEMENT SCREEN!!!___________________";
    cout << "\n\n\t\t1) Property Management";
    cout << "\n\n\t\t2) Customer Management";
    cout << "\n\n\t\t3) Bill Management";
    cout << "\n\n\t\t4) Exit";

    cout << "\n\n\t\tEnter Choice:";
    cin >> mainChoice;

    switch (mainChoice)
    {
        // case1:
    case 1:

    {
        system("CLS");
        case1();
        break;
    }

    case 2:
    {
        system("CLS");
        case2();
        break;
    }
    case 3:
    {
        system("CLS");
        case3();
        break;
    }
    }
    // }
}

bool loginSystem()
{
    string userName;
    string password;
    bool isLoggedIn = false;
    cout << "\n\n\n\t\t\t\t___________________Real Estate Login Screen!!!___________________";
    cout << "\n\n\t\tEnter User Name:";
    cin >> userName;
    cout << "\n\n\t\tEnter Password:";
    cin >> password;
    if (userName == "Sattar" && password == "123")
    {
        isLoggedIn = true;
        cout << "\n\n\t\t\t\tLogged In successfully.........";
        Sleep(2000);
        system("CLS");
        return isLoggedIn;
    }
    else
    {
        cout << "\n\n\t\t\t\tLogIn Failed!!!!!";
        Sleep(2000);
        system("CLS");
        loginSystem();
    }
}

int main()
{
    // loginSystem();
    mainMenu();
    return 0;
}
