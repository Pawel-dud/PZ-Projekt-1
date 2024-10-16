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

    void dodaj_na_poczatek(int id) 
    {
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

    void dodaj_na_koniec(int id) 
    {
        elementy *nowy = new elementy;
        nowy->id = id;
        nowy->nastepny = NULL;
        nowy->poprzedni = koniec;

        if (koniec) {
            koniec->nastepny = nowy;
        }
        koniec = nowy;

        if (!poczatek) {
            poczatek = koniec;
        }
        licznik++;
    }


    void dodaj_pod_indeks(int id, unsigned indeks) 
    {
        if (indeks > licznik) 
        {
            cout << "Indeks poza zakresem!" << endl;
            return;
        }
        if (indeks == 0) 
        {
            dodaj_na_poczatek(id);
        } else if (indeks == licznik) 
        {
            dodaj_na_koniec(id);
        } else 
        {
            elementy *nowy = new elementy;
            nowy->id = id;
            elementy *p = poczatek;

            for (unsigned i = 0; i < indeks - 1; i++) 
            {
                p = p->nastepny;
            }
            nowy->nastepny = p->nastepny;
            nowy->poprzedni = p;
            p->nastepny = nowy;
            if (nowy->nastepny) 
            {
                nowy->nastepny->poprzedni = nowy;
            } else 
            {
                koniec = nowy;
            }
            licznik++;
        }
    }
};



int main() {
 cout<<"Hello";

}