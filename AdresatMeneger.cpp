#include "AdresatMeneger.h"

void AdresatMeneger::dodajAdresata(){
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    int idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, przekazaneIdZalogowanegoUzytkownika);
    adresat = podajDaneNowegoAdresata(idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMeneger::podajDaneNowegoAdresata(int idOstatniegoAdresata){
    Adresat adresat;
    string temp = "";

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(przekazaneIdZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    temp = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie());
    adresat.ustawImie(temp);

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    temp = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko());
    adresat.ustawNazwisko(temp);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

string AdresatMeneger::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst){
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatMeneger::ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika){
    przekazaneIdZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
}

void AdresatMeneger::wyswietlWszystkichAdresatow(){
    system("cls");
    if (!adresaci.empty()){
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMeneger::wyswietlDaneAdresata(Adresat adresat){
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMeneger::wyczyscVektorZAdresatami(){
    adresaci.clear();
}
