#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMeneger(nazwaPlikuZUzytkownikami){//lista inicjalizacyjna przekazujaca nazewPlioku... do kolejnych klas
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
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMeneger.wylogowanieUzytkownika();
}
