#include <iostream>
#include <string>
using namespace std;

int generateID()
{
	static int s_id = 0;
	return ++s_id;
}

struct NMUON
{
    string ten;
    string tuoi, sdt, idsach;
    tm ngaymuon, ngaytra;
};

class NM
{
private:
    string line;
    int sonm, j, ID;      //sonm = So nguoi muon
    NMUON *nm;
public:
    NM()
    {
        ID = generateID();
        sonm = 0;
        nm = NULL;
    }
    void nhapttin();
    void ghitep(char *ttep);
    void doctep(char *ttep);
    void newID();
    void outID();
    void resetID();
    void allline(char *ttep);
    void timSDT(char *ttep);
};
