#include "Class.hpp"
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

void NM::doctep(char *ttep)
{
    string s_word;
    cout<<"Nhap ID cua nguoi muon: ";
    cin>>s_word;
    ifstream f(ttep, ios::in);
    if(f.is_open())
    {
        while(getline(f, line))
        {
            size_t found = line.find(s_word);
            if(line.rfind(s_word, 0) != string::npos)
            {
                cout<<line<<"\n================================================================================================\n";
                break;
            }
        }
        f.close();
    }
    else{
        cout<<"\nKhong mo duoc file.";
        cout<<"Press any key to exit.";
        getch();
    }

}

void NM::timSDT(char *ttep){
    string nm_sdt;
    cout<<"Nhap SDT cua nguoi muon: ";
    cin>>nm_sdt;
    ifstream f(ttep, ios::in);
    if(f.is_open()){
        while(getline(f, line)){
            if(line.find(nm_sdt, 0) != string::npos){
                cout<<line<<"\n================================================================================================\n";
            }
        }f.close();
    }
    else{
        cout<<"\nKhong mo duoc file."<<endl;
        cout<<"Press any key to exit.";
        getch();
    }

}


void NM::allline(char *ttep)
{
    ifstream f(ttep, ios::in);
    if(f.is_open()){
        while(getline(f, line)){
            cout<<line<<endl;
        }
    }
    else
    {
        cout<<"\nUnable to open file!"<<endl;
        cout<<"Press any key to exit.";
        getch();
    }
}

int main()
{
    NM n;
    string choice1;
    choice1 = "";
    cout<<"1. Tim nguoi muon.\n2. In tat ca danh sach nguoi muon.\n3. Tim nguoi muon bang so dien thoai\n4. Thoat chuong trinh.";
    cin>>choice1;
    if(choice1 == "1")
    {
        n.doctep("NM.dat");
        mainCheck = false;
        mc();
    }
    if(choice1 == "2")
    {
        n.allline("NM.dat");
        cout<<"Da xong!\n=================================\n";
        mainCheck = false;
        mc();
    }
    if(choice1 == "3")
    {
        n.timSDT("NM.dat");
        cout<<"Da xong!\n=================================\n";
        mainCheck = false;
        mc();
    }
    if(choice1 == "4")
    {
        cout<<"Press any key to exit.";
        getch();
    }
    else
    {
        cout<<"\nVui long nhap 1, 2, 3 hoac 4.\n";
        mainCheck = false;
        mc();
    }
}

void mc()
{
    if(mainCheck == false)
    {
        main();
    }
}
