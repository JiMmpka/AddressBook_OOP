#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>
#include <cctype>
//#include <string>
//#include <cstring>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include <vector>
/*
#include <windows.h>
#include <cstdlib>

*/

using namespace std;

class PlikZAdresatami{
    const string nazwaPlikuZAdresatami;
    int idOstatniegoAdresata;

    //bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

public:
    PlikZAdresatami(string NAZWA_PLIKU_Z_ADRESATAMI) : nazwaPlikuZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI){}; // aby zdefiniowaæ sta³¹ globaln¹ const trzeba j¹ zainicjalizowaæ w liœcie inicjalizacyjnej konstruktora w pliku nag³ówkowym lub w pliku cpp
    void dopiszAdresataDoPliku(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

};
#endif // PLIKZADRESATAMI_H
