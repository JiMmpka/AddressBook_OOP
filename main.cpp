#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main(){
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    char wybor;

    while (true){
        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany()){
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            ksiazkaAdresowa.wypiszWszystkichUzytkownikow(); //TEMP

            switch (wybor){
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else{
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor){
            case '1':
                ksiazkaAdresowa.dodajAdresata(); // TO DOO po usunięciu wszystkich adresatów z pliku dodaje adresata z kolejnym id a nie z id 1. nie ma tego po ponownym uruchomieniu.Funkcje kontrolują ID ostatniego adresata przy dodawaniu adresata ale nie kontrolują go przy usuwaniu adresatów.
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
               // edytujAdresata(adresaci); //TO DOO zrobić tą funkcję
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}

/*
int _main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    //TO DOO menu oraz zamiast if(idZalogwanegoU¿ytkownika = 0) w menu zrobic metodê bool czyUzytkownikJestZalogowany()
    return 0;
}
*/
