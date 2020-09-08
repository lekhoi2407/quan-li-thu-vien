#include <iostream>
#include <string>

using namespace std;

struct BOOK
{
    string name;        //tl = the loai
    string id;
    string tacgia;
    string tl;
};

class B
{
private:
    string line;
    int sach;
    BOOK *b;
public:
    B()
    {
        sach = 0;
        b = NULL;
    }
    void nhapsach(char *ttep);
    void xuatsach(char *ttep);
};
