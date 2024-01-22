#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMeneger(nazwaPlikuZUzytkownikami), adresatMeneger(nazwaPlikuZAdresatami){//lista inicjalizacyjna przekazujaca nazewPlioku... do kolejnych klas
    uzytkownikMeneger.wczytajUzytkownikowZPliku(); // pozostale inicjacje
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMeneger.rejestracjaUzytkownika();

}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMeneger.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMeneger.logowanieUzytkownika();
    if (uzytkownikMeneger.czyUzytkownikJestZalogowany())
        adresatMeneger.ustawIdZalogowanegoUzytkownika(uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMeneger.wylogowanieUzytkownika();
    adresatMeneger.wyczyscVektorZAdresatami();
}

void KsiazkaAdresowa::dodajAdresata(){
     adresatMeneger.dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMeneger.wyswietlWszystkichAdresatow();
};
