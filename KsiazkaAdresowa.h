#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"
#include "AdresatMeneger.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa{
    UzytkownikMeneger uzytkownikMeneger;
    AdresatMeneger *adresatMeneger; // wskaznik na obiekt adresatMeneger który pozwoli utworzyæ obiekt pózniej
    const string NAZWA_PLIKU_Z_ADRESATAMI;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMeneger(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
        adresatMeneger = NULL;
    };
    ~KsiazkaAdresowa(){
        delete adresatMeneger;
        adresatMeneger = NULL;
    }
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();
};

#endif
