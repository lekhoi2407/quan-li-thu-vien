#include "Class.hpp"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool mainCheck = true;

void nhapngay()
{
    string date;
    int d, m, y;
    cin >> d; // read the day
    while (cin.get() != '/' ) // make sure there is a slash between DD and MM
        {
            cout << "Nhap dung format nhu sau: dd/mm/yyyy\n";
            cin>>d;

        }
    cin >> m; // read the month
    while (cin.get() != '/' ) // make sure there is a slash between MM and YYYY
        {
            cout << "Nhap dung format nhu sau: dd/mm/yyyy\n";
            cin>>m;
        }
    cin >> y;
}

void NM::nhapttin()
{
    cout<<"============================\nSo nguoi muon can nhap: ";
    cin>>sonm;
    int n = sonm;
    int j;
    nm = new NMUON[n+1];
    for (int i = 1; i <= n; ++i)
    {
        newID();
        cout<<"============================\nID nguoi muon: "<<ID<<endl;
        cout<<"Ho ten: "<<endl;
        getline(cin.ignore(), nm[i].ten);
        cout<<"Tuoi: ";
        cin>>nm[i].tuoi;
        cout<<"SDT: ";
        cin>>nm[i].sdt;
        cout<<"ID sach dang muon: ";
        cin>>nm[i].idsach;
        cout<<"Ngay muon sach: ";
        nhapngay();
        cout<<"Ngay tra sach: ";
        nhapngay();
        time_t curr_time;
        curr_time = time(NULL);
        char* dt = ctime(&curr_time);
        ofstream f("NM.dat", ios::app);
        f<<ID<<setw(10)<<nm[i].ten<<setw(10)<<nm[i].tuoi<<setw(20)<<nm[i].sdt<<setw(10)<<nm[i].idsach<<setw(30)<<dt<<endl;
        f.close();
        outID();
    }
}

/*void NM::ghitep(char *ttep)
{
    time_t curr_time;
    curr_time = time(NULL);
    char* dt = ctime(&curr_time);
    ofstream f(ttep, ios::app);
    f<<ID<<setw(10)<<nm[i].ten<<setw(10)<<nm[i].tuoi<<setw(20)<<nm[i].sdt<<setw(10)<<nm[i].idsach<<setw(30)<<dt<<endl;
    f.close();
}*/
void NM::outID()
{
    ofstream idf("idf.dat", ios::out | ios::trunc);
    idf<<ID;
    idf.close();
}

void NM::newID()
{
    string line;
    ifstream idf("idf.dat", ios::in);
    if (idf.is_open())
    {
    while ( getline (idf,line) )
    {
        ID = stoi(line)+1;
    }

    idf.close();
    }

    else {cout << "FATAL ERROR.";
    }

}

void NM::resetID()
{
    ID = 0;
    ofstream idf("idf.dat", ios::out | ios::trunc);
    idf<<ID;
    idf.close();
    cout<<"\nDa reset ID nguoi muon.\n============================\n";
}

void xoatep(char *ttep);
void mc();

int main()
{
    NM n;
    mainCheck = true;
    string choice1;
    choice1 = "";
    cout<<"1. Nhap thong tin nguoi doc.\n2. Xoa danh sach nguoi doc.\n3. Reset ID nguoi muon.\n4. Thoat chuong trinh.";
    cin>>choice1;
    if(choice1 == "1")
    {
        n.nhapttin();
        cout<<"\n============================\nHoan thanh.\n";
        mainCheck = false;
        mc();
    }
    if(choice1 == "2")
    {
        xoatep("NM.dat");
        mainCheck = false;
        mc();
    }
    if(choice1 == "3")
    {
        NM n;
        n.resetID();
        mainCheck = false;
        mc();
    }
    if(choice1 == "4")
    {
        cout<<"============================\nBam phim bat ki de thoat.";
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

void xoatep(char *ttep)
{
    string choice2;
    cout<<"============================\nBan co chac muon xoa danh sach nguoi muon? (y/n): ";
    cin>>choice2;
    for_each(choice2.begin(), choice2.end(), [](char & c){
        c = ::toupper(c);
    });
    if (choice2=="Y")
    {
        if( remove( "NM.dat" ) != 0 )
        {
            cout<<"\nError: Unable to remove file or file not found.\n============================\n";
        }
        else
        {
            cout<<"\nXoa tep thanh cong\n============================\n";
        }
    }
    if  (choice2=="N")
    {
        main();
    }

}
