#include "class.cpp"



int main() 
{
    metody m;
    m.dodaj_na_poczatek(2);
    m.dodaj_na_koniec(8);
    m.dodaj_na_koniec(5);
    m.dodaj_pod_indeks(3, 1);

    cout << "Lista: " << endl;
    m.pokaz_liste();

    cout<< "Lista w odwrotnej kolejnosci: " << endl;
    m.pokaz_liste_w_odwrotnej_kolejnosci();

    elementy *aktualny = m.pokaz_poczatek();
    cout<< "Wyświetl następny element: " << endl;
    m.pokaz_nastepny(aktualny);

    cout << "Wyświetl poprzedni element: " << endl;
    m.pokaz_poprzedni(aktualny);

    m.usun_z_poczatku();
    cout << "Po usunieciu z poczatku: " << endl;
    m.pokaz_liste();

    m.usun_z_konca();
    cout << "Po usunieciu z konca: " << endl;
    m.pokaz_liste();

    m.usun_z_indeksu(1);
    cout << "Po usunieciu z indksu 1: " << endl;
    m.pokaz_liste();

    m.czyszczenie();
    cout << "Po czyszczeniu: " << endl;
    m.pokaz_liste();

}