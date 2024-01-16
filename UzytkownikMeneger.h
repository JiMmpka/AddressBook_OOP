#ifndef UZYTKOWNIKMENEGER_H
#define UZYTKOWNIKMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMeneger{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami; // jezli okrzysta sie z obiektu w kilku miejscach to mozna go utworzyc w pliku nag�owkowym

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif // UZYTKOWNIKMENEGER_H
