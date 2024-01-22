#ifndef ADRESATMENEGER_H
#define ADRESATMENEGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMeneger.h"

using namespace std;

class AdresatMeneger{
    int przekazaneIdZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata(int idOstatniegoAdresata);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMeneger(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};//przekazanie przez liste inicjalizacyjna nazwyPliku do klasy plikZAdresatami
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyczyscVektorZAdresatami();
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
};
#endif // ADRESATMENEGER_H
