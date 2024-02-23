#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true){
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true){
            plikTekstowy << liniaZDanymiAdresata;
        }
        else{
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat){
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true){
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)){
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)){
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;


    daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    przypisanieIdOstatniegoAdresata(daneOstaniegoAdresataWPliku);

    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku){
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true){
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami){
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++){
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else{
            switch(numerPojedynczejDanejAdresata){
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata(){
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata){
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string daneOstaniegoAdresataWPliku = "";
    string danePrzedostaniegoAdresata = "";
    int ileLinijekZapisanoWPlikuTymczasowym = 0;
    int idAdresataZWczytanejLiniiZPliku{};

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good()){
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)){
            idAdresataZWczytanejLiniiZPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            if (idAdresataZWczytanejLiniiZPliku != idUsuwanegoAdresata){
                if (ileLinijekZapisanoWPlikuTymczasowym > 0){
                    tymczasowyPlikTekstowy << endl;
                }
                tymczasowyPlikTekstowy << wczytanaLinia;
                ileLinijekZapisanoWPlikuTymczasowym++;
            }
        danePrzedostaniegoAdresata = daneOstaniegoAdresataWPliku;
        daneOstaniegoAdresataWPliku = wczytanaLinia;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, pobierzNazwePliku());
    }
    przypisanieIdOstatniegoAdresata(daneOstaniegoAdresataWPliku);

    if (idOstatniegoAdresata == idUsuwanegoAdresata){
        przypisanieIdOstatniegoAdresata(danePrzedostaniegoAdresata);
    }
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem){
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa){
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::przypisanieIdOstatniegoAdresata(string daneOstaniegoAdresataWPliku){
    if (daneOstaniegoAdresataWPliku != "")
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    else
        idOstatniegoAdresata = 0;
}

void PlikZAdresatami::edytujWybranegoAdresataWPliku(Adresat adresat){
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "", liniaZDanymiAdresataOddzielonePionowymiKreskami{};
    int numerWczytanejLinii = 1;
    int idAdresataZWczytanejLiniiZPliku{}, idEdytowanegoAdresata{};

    liniaZDanymiAdresataOddzielonePionowymiKreskami = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    idEdytowanegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresataOddzielonePionowymiKreskami);

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true){
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)){
            idAdresataZWczytanejLiniiZPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);

           if (idAdresataZWczytanejLiniiZPliku == idEdytowanegoAdresata){
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else{
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, pobierzNazwePliku());
    }
}
