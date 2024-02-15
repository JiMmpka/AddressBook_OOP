#include <iostream>
#include "KsiazkaAdresowa.h"
//#include "UzytkownikMeneger.h"

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
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
               // idUsunietegoAdresata = usunAdresata(adresaci);
               // idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
               // edytujAdresata(adresaci);
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
