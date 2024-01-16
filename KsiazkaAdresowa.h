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
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
