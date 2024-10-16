#include <iostream>
using namespace std;

struct elementy
{
    elementy *nastepny, *poprzedni;
    int id;
};

class metody
{
    private:
    elementy *poczatek, *koniec;
    unsigned licznik;

    public:
    metody()
    {
        poczatek = NULL;
        koniec = NULL;
        licznik = 0;
    }

    ~metody()
    {
        czyszczenie();
    }

     void dodaj_na_poczatek(int id) {
        elementy *nowy = new elementy;
        nowy->id = id;
        nowy->nastepny = poczatek;
        nowy->poprzedni = NULL;

        if (poczatek) {
            poczatek->poprzedni = nowy;
        }
        poczatek = nowy;

        if (!koniec) {
            koniec = poczatek;
        }
        licznik++;
    }

};



int main() {
 cout<<"Hello";

}