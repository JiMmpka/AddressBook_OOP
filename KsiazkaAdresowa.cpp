#include "KsiazkaAdresowa.h"

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego(){
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika(){
    return uzytkownikMeneger.wybierzOpcjeZMenuUzytkownika();
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
        adresatMeneger = new AdresatMeneger(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMeneger.wylogowanieUzytkownika();
    delete adresatMeneger;
    adresatMeneger = NULL; // ustawienie wskaznika na pusta komórke
}

void KsiazkaAdresowa::dodajAdresata(){
     adresatMeneger->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMeneger->wyswietlWszystkichAdresatow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){
    return uzytkownikMeneger.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    adresatMeneger->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    adresatMeneger->wyszukajAdresatowPoNazwisku();
}
