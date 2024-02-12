#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMeneger.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    //TO DOO menu oraz zamiast if(idZalogwanegoUżytkownika = 0) w menu zrobic metodę bool czyUzytkownikJestZalogowany()
    return 0;
}
