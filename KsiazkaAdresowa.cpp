#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMeneger.rejestracjaUzytkownika();

}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMeneger.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMeneger.logowanieUzytkownika();
    if (uzytkownikMeneger.czyUzytkownikJestZalogowany())
        adresatMeneger = new AdresatMeneger(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
        //AdresatMeneger.ustawIdZalogowanegoUzytkownika(uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMeneger.wylogowanieUzytkownika();
    //adresatMeneger.wyczyscVektorZAdresatami();
    delete adresatMeneger;
    adresatMeneger = NULL; // ustawienie wskaŸnika na pust¹ komórkê
}

void KsiazkaAdresowa::dodajAdresata(){
     adresatMeneger->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMeneger->wyswietlWszystkichAdresatow();
};
