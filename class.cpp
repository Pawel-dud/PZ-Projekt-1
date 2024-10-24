#include "struct.cpp"

/// @brief Definiuje listę, zmienne i metody
class metody    /**Klasa zarządzająca listą dwukierunkową*/
{
    private:
    /// @brief Tworzy wskaźniki "początek" i "koniec"
    elementy *poczatek, *koniec;
    /// @brief Licznik elemętów listy
    unsigned licznik; 

    public:
    /// @brief Konsturktor
    metody()    
    {
        poczatek = NULL;
        koniec = NULL;
        licznik = 0;
    }

    /// @brief Destruktor
    ~metody()
    {
        ///Wywołuje metode czyszczenie()
        czyszczenie();
    }

    ///Zwraca początek
    elementy* pokaz_poczatek()
     {
        return poczatek;
     }

    /// @brief Dodaje element na początku listy
    /// @param id - Wartość elementu
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

    /// @brief Dodaje element na koniec listy
    /// @param id - Wartość elementu
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

    /// @brief Dodaje element w wybranym miejcu po numerze indeksu
    /// @param id - Wartość elementu
    /// @param indeks - Indeks elementu
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

            for (unsigned i = 0; i < indeks; i++) 
            {
                p = p->nastepny;
            }
            nowy->nastepny = p;
            nowy->poprzedni = p->poprzedni;
            p->poprzedni->nastepny = nowy;
            p->poprzedni = nowy;

            licznik++;
        }
    }

    /// @brief Usuwa pierwszy element listy
    void usun_z_poczatku() 
    {
        if (poczatek) 
        {
            elementy *p = poczatek;
            poczatek = poczatek->nastepny;
            if (poczatek) 
            {
                poczatek->poprzedni = NULL;
            } else 
            {
                koniec = NULL;
            }
            delete p;
            licznik--;
        }
    }


    /// @brief Usuwa ostatni element listy
    void usun_z_konca()   
    {
        if (koniec) 
        {
            elementy *p = koniec;
            koniec = koniec->poprzedni;
            if (koniec) 
            {
                koniec->nastepny = NULL;
            } else 
            {
                poczatek = NULL;
            }
            delete p;
            licznik--;
        }
    }

    /// @brief Usuwa element z wybranego miejsca po numerze indeksu
    /// @param indeks - Indeks
    void usun_z_indeksu(unsigned indeks)    
    {
        if (indeks < 1 || indeks > licznik) 
        {
            cout << "Indeks poza zakresem!" << endl;
            return;
        }
        elementy *p = poczatek;
        for (unsigned i = 1; i < indeks; i++) 
        {
            p = p->nastepny;
        }

        if (p->poprzedni) 
        {
            p->poprzedni->nastepny = p->nastepny;
        } else 
        {
            poczatek = p->nastepny;
        }

        if (p->nastepny) 
        {
            p->nastepny->poprzedni = p->poprzedni;
        } else 
        {
            koniec = p->poprzedni;
        }

        delete p;
        licznik--;
    }

     /// @brief Wyświetla elementy listy od początku do końca
     void pokaz_liste()
     {
        elementy *p = poczatek;
        while (p) 
        {
            cout << p->id << " ";
            p = p->nastepny;
        }
        cout << endl;
    }


     /// @brief Wyświetla elementy listy od końca do początku
     void pokaz_liste_w_odwrotnej_kolejnosci()      
     {
        elementy *p = koniec;
        while (p) {
            cout << p->id << " ";
            p = p->poprzedni;
        }
        cout << endl;
    }

    
    /// @brief Wyświetla następny element dla danego wskaźnika
    /// @param p - Indeks elementu
    void pokaz_nastepny(elementy *p)   
    {
        if (p && p->nastepny) 
        {
            cout << "Nastepny element: " << p->nastepny->id << endl;
        } else 
        {
            cout << "Brak nastepnego elementu." << endl;
        }
    }

    /// @brief Wyświetla poprzedni element dla danego wskaźnika
    /// @param p - Indeks elementu
    void pokaz_poprzedni(elementy *p)       
    {
        if (p && p->poprzedni) 
        {
            cout << "Poprzedni element: " << p->poprzedni->id << endl;
        } else 
        {
            cout << "Brak poprzedniego elementu." << endl;
        }
    }

     /// @brief Czyści listę usuwając wszystkie elemęty
     void czyszczenie()     
     {
        while (poczatek) 
        {
            usun_z_poczatku();
        }
     }

};
