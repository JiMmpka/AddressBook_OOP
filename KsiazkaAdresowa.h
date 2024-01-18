#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"

using namespace std;

class KsiazkaAdresowa{
    UzytkownikMeneger uzytkownikMeneger;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);//przekazywanie do konstruktora nazwy pliku z funkcji main w pliku cpp konstruktor moze zawiwrac pozostale inicjacje
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
};

#endif
