#include "UzytkownikMeneger.h"

int UzytkownikMeneger::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
};

void UzytkownikMeneger::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMeneger::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login = "";
    string haslo = "";

    do
    {
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        //uzytkownik.login = wczytajLinie();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();

    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMeneger::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMeneger::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;

    /*
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
    */
}

void UzytkownikMeneger::wypiszWszystkichUzytkownikow(){
    for (int i = 0; i < uzytkownicy.size(); i++){
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
        }
}

void UzytkownikMeneger::wczytajUzytkownikowZPliku(){
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMeneger::logowanieUzytkownika(){
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    //idZalogowanegoUzytkownika = 0; // przemyœleæ czy to jest potrzebne
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    while (itr != uzytkownicy.end()){
        if (itr -> pobierzLogin() == login){
            for (int iloscProb = 3; iloscProb > 0; iloscProb--){
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo){
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikMeneger::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMeneger::wylogowanieUzytkownika(){
    idZalogowanegoUzytkownika = 0;
    //adresaci.clear();
}

bool UzytkownikMeneger::czyUzytkownikJestZalogowany(){
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

