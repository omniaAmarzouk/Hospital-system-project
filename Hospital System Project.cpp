

#include <iostream>
using namespace std;
string name [20][5];
int status[20][5];
int queue[20];

void shift_right(int spec, string names_sp[], int status_sp[])
{
    int len = queue[spec];
    for (int i = len - 1; i >= 0; --i) {	
        names_sp[i + 1] = names_sp[i];
        status_sp[i + 1] = status_sp[i];
    }
    queue[spec]++;
}
void shift_left(int spec, string names_sp[], int status_sp[])
{
    int len = queue[spec];
    for (int i =1; i <len; ++i) {
        names_sp[i - 1] = names_sp[i];
        status_sp[i - 1] = status_sp[i];
    }
    queue[spec]--;
}

void Add() {
    cout << "Enter specialization, name, status: ";
    int spec, stat; string nam;
    cin >> spec >> nam >> stat;
    int pos = queue[spec];
    if (pos >= 5)
    {
        cout << "Sorry we can't add more patients for this specialization\n";
        return;
    }
    if (stat)
    {
        shift_right(spec, name[spec], status[spec]);
        name[spec][0] = nam, status[spec][0] = stat;
    }
    else
    {
     name[spec][pos] = nam; status[spec][pos] = stat;
     queue[spec]++;
    }
}
void Print(int spec,string names[],int statuss[]) {
    int len = queue[spec];
    if (len == 0) return;
    cout << "There are " << len << " patients in specialization " << spec << '\n';
    for (int i = 0; i < len; ++i)
    {
        cout << names[i] << " ";
        if (statuss[i])
            cout << "urgent\n";
        else
            cout << "regular\n";
    }
    cout << '\n';
}
void print() {
    cout << "****************************\n";
    for (int i = 0; i < 20; ++i)
        Print(i, name[i], status[i]);
}
void Get()
{
    int spec;
    cout << "Enter specialization: ";
    cin >> spec;
    int len = queue[spec];
    if (!len)
    {
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }
    cout << name[spec][0] << " please go with the Dr";
    shift_left(spec, name[spec], status[spec]);
}
int menu()
{
    int choice;
    cout << "Enter your choice: \n";
    cout << "1) Add new patient\n";
    cout << "2) Print all patients\n";
    cout << "3) Get next patient\n";
    cout << "4) Exit\n";
    cin >> choice;
    if (choice >= 1 && choice <= 4)
    {
        switch (choice)
        {
        case 1:
            Add();
            break;
        case 2:
            print();
            break;
        case 3:
            Get();
            break;
        default:
            return 0;
        }
    }
    else
        cout << "Invalid choice. please Enter number from 1 to 4.";
    return choice;
}
int main()
{
    int choice;
    do {
        choice = menu();
    } while (choice != 4); 
    return 0;
}

