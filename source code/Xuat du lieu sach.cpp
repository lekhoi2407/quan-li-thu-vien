#include "Sach.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <ctype.h>

using namespace std;

bool mainCheck = true;
void mc();

void B::xuatsach(char *ttep){
    string idsach;
    cout<<"Nhap ID cua sach: ";
    cin>>idsach;
    ifstream f(ttep, ios::in);
    if(f.is_open())
    {
        while(getline(f, line)){
            if(line.rfind(idsach, 0) != string::npos){
                cout<<line<<"\n================================================================================================\n";
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

int main(){
    B b;
    b.xuatsach("Sach.dat");
    mainCheck = false;
    mc();
}

void mc(){
    if(mainCheck == false)
    {
        main();
    }
}


