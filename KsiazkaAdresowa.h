#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"
#include "AdresatMeneger.h"

using namespace std;

class KsiazkaAdresowa{
    UzytkownikMeneger uzytkownikMeneger;
    AdresatMeneger adresatMeneger;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);//przekazywanie do konstruktora nazwy pliku z funkcji main w pliku cpp konstruktor moze zawiwrac pozostale inicjacje
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif
