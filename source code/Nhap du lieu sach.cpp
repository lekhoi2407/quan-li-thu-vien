#include "Sach.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

using namespace std;

bool mainCheck = true;

void mc();

void B::nhapsach(char *ttep)
{
    cout<<"\n============================\nSo sach can nhap: ";
    cin>>sach;
    int n = sach;
    b = new BOOK[n+1];
    for (int i = 1; i <= n; ++i)
    {
        cout<<"============================\nID sach(6 chu so): ";
        cin>>b[i].id;
        cout<<"Ten sach: ";
        getline(cin>>ws, b[i].name);
        cout<<"Tac gia: ";
        getline(cin>>ws, b[i].tacgia);
        cout<<"The loai: ";
        getline(cin>>ws, b[i].tl);
        ofstream f(ttep, ios::app);
        f<<b[i].id<<"         "<<b[i].name<<"    "<<b[i].tacgia<<"    "<<b[i].tl<<endl;
        f.close();
    }
}

int main()
{
    B b;
    b.nhapsach("Sach.dat");
    cout<<"Da xong!"<<endl;
    mainCheck = false;
    mc();
}

void mc(){
    if(mainCheck == false)
    {
        main();
    }
}
