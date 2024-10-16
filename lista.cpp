#include <iostream>
using namespace std;

struct elementy
{
    elementy * następny, *poprzedni;
    int klucz;
};

class lista
{
    private:
    elementy * poczatek, *koniec;
    unsigned licznik;

    public:
    lista()
    {
        poczatek = NULL;
        koniec = NULL;
        licznik = 0;
    }

    ~lista()
    {

    }
};

int main() {
 cout<<"Hello";

}