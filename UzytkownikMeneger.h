#ifndef UZYTKOWNIKMENEGER_H
#define UZYTKOWNIKMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikMeneger{
    int idZalogowanegoUzytkownika; //TO DOO problem ze statycznym idZalogowanegoUzytkownika w funkcji pobierzIdZalogowanegoUzytkownika idZalogowanegoUzytkownika
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami; // jezli okrzysta sie z obiektu w kilku miejscach to mozna go utworzyc w pliku nag³owkowym

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    UzytkownikMeneger(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){idZalogowanegoUzytkownika = 0;};//przekazanie przez liste inicjalizacyjna nazwyPliku do klasy plikZUzytkownikami
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
};

#endif // UZYTKOWNIKMENEGER_H
