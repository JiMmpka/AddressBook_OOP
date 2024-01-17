#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMeneger.h"

using namespace std;

class KsiazkaAdresowa{
    //int idOstatniegoAdresata;
    //int idUsunietegoAdresata;

    UzytkownikMeneger uzytkownikMeneger;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);//przekazywanie do konstruktora nazwy pliku z funkcji main w pliku cpp konstruktor moze zawiwrac pozostale inicjacje
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
