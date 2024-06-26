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

Uzytkownik UzytkownikMeneger::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login = "";
    string haslo = "";

    do{
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();

    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMeneger::pobierzIdNowegoUzytkownika(){
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMeneger::czyIstniejeLogin(string login){
    for (int i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMeneger::logowanieUzytkownika(){
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
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

void UzytkownikMeneger::zmianaHaslaZalogowanegoUzytkownika(){
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++){
        if (itr -> pobierzId() == idZalogowanegoUzytkownika){
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMeneger::wylogowanieUzytkownika(){
    idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMeneger::czyUzytkownikJestZalogowany(){
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

char UzytkownikMeneger::wybierzOpcjeZMenuUzytkownika(){
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
