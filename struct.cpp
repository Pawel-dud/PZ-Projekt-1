#include <iostream>
using namespace std;

/// @brief Definiuje element listy
struct elementy     /**Struktura o nazwie elementy zawierająca nr.elementu i wskaźniki*/
{
    ///Wskaźnik do następnego elementu
    elementy *nastepny, 
    ///Wskaźnik do porzedniego elementu
    *poprzedni;
    ///Wartość elementu
    int id;     
};