#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"
#include "AdresatMeneger.h"

using namespace std;

class KsiazkaAdresowa{
    UzytkownikMeneger uzytkownikMeneger;
    AdresatMeneger *adresatMeneger; // wskaznik na obiekt adresatMeneger kt�ry pozwoli utworzy� obiekt p�zniej
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMeneger(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){//lista inicjalizacyjna przekazujaca nazewPlioku... do kolejnych klas;//przekazywanie do konstruktora nazwy pliku z funkcji main w pliku cpp konstruktor moze zawiwrac pozostale inicjacje
        adresatMeneger = NULL;
    };
    ~KsiazkaAdresowa(){
        delete adresatMeneger;
        adresatMeneger = NULL;
    }
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif
