#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

enum Stanowisko {
	Nauczyciel,
	Dyrektor,
	Sekretarka,
	Wychowawca
};
string Stanowiska[] = {
	"Nauczyciel",
	"Dyrektor",
	"Sekretarka",
	"Wychowawca"
};

class PracownikSzkoly {
protected:
	int id;
	string imie;
	string nazwisko;
	double stawka;
	int godziny;
	Stanowisko stanowisko;
public:
	PracownikSzkoly(int id, string imie, string nazwisko, double stawka, int godziny, Stanowisko stanowisko) : id(id), imie(imie), nazwisko(nazwisko), stawka(stawka), godziny(godziny), stanowisko(stanowisko) {}
	PracownikSzkoly(int id, string imie, string nazwisko, double stawka, int godziny, string stanowisko) : id(id), imie(imie), nazwisko(nazwisko), stawka(stawka), godziny(godziny) { setStanowisko(stanowisko); }

	int getId() const { return id; }
	string getImie() const { return imie; }
	string getNazwisko() const { return nazwisko; }
	double getStawka() const { return stawka; }
	int getGodziny() const { return godziny; }
	string getStanowisko() const {
		return Stanowiska[stanowisko];
	}
	double getWynagrodzenie() const { return stawka * godziny; }

	void setStawka(double stawka) { this->stawka = stawka; }
	void setGodziny(int godziny) { this->godziny = godziny; }
	void setStanowisko(Stanowisko stanowisko) { this->stanowisko = stanowisko; }
	void setStanowisko(string stanowisko) {
		for (int i = 0; i < 4; i++) {
			if (stanowisko == Stanowiska[i]) {
				this->stanowisko = (Stanowisko)i;
			}
		}
	}

	void print() const {
		cout << "ID: " << getId() << endl;
		cout << "\tImie: " << getImie() << endl;
		cout << "\tNazwisko: " << getNazwisko() << endl;
		cout << "\tStanowisko: " << getStanowisko() << endl;
		cout << "\tIlość godzin w tygodniu: " << getGodziny() << endl;
		cout << "\tStawka: " << getStawka() << endl;
		cout << "\tWynagrodzenie tygodniowe: " << getWynagrodzenie() << endl;
	}
};

enum Przedmiot {
	Polski,
	Angielski,
	Niemiecki,
	Hiszpanski,
	Matematyka,
	Fizyka,
	Chemia,
	Biologia,
	Geografia,
	Historia,
	Religia,
	WF,
	Informatyka,
	Przyroda,
	WoS,
	HiT,
	WiedzaOKulturze
};
string Przedmioty[] = {
	"Polski",
	"Angielski",
	"Niemiecki",
	"Hiszpanski",
	"Matematyka",
	"Fizyka",
	"Chemia",
	"Biologia",
	"Geografia",
	"Historia",
	"Religia",
	"WF",
	"Informatyka",
	"Przyroda",
	"WoS",
	"HiT",
	"Wiedza o Kulturze"
};

class Nauczyciel : public PracownikSzkoly {
	Przedmiot przedmiot;
public:
	Nauczyciel(int id, string imie, string nazwisko, double stawka, int godziny, Przedmiot przedmiot) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Nauczyciel), przedmiot(przedmiot) {}
	Nauczyciel(int id, string imie, string nazwisko, double stawka, int godziny, string przedmiot) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Nauczyciel) { setPrzedmiot(przedmiot); }

	string getPrzedmiot() const {
		return Przedmioty[przedmiot];
	}

	void setPrzedmiot(Przedmiot przedmiot) { this->przedmiot = przedmiot; }
	void setPrzedmiot(string przedmiot) {
		for (int i = 0; i < 17; i++) {
			if (przedmiot == Przedmioty[i]) {
				this->przedmiot = (Przedmiot)i;
			}
		}
	}

	void print() const {
		PracownikSzkoly::print();
		cout << "\tNauczany przedmiot: " << getPrzedmiot() << endl;
	}
};

class Dyrektor : public PracownikSzkoly {
public:
	Dyrektor(int id, string imie, string nazwisko, double stawka, int godziny) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Dyrektor) {}
};

class Sekretarka : public PracownikSzkoly {
public:
	Sekretarka(int id, string imie, string nazwisko, double stawka, int godziny) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Sekretarka) {}
};

class Wychowawca : public PracownikSzkoly {
private:
	string klasa;
public:
	Wychowawca(int id, string imie, string nazwisko, double stawka, int godziny, string klasa) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Wychowawca), klasa(klasa) {}

	string getKlasa() const { return klasa; }

	void setKlasa(string klasa) { this->klasa = klasa; }

	void print() const {
		PracownikSzkoly::print();
		cout << "\tWychowywana klasa: " << getKlasa() << endl;
	}
};

vector<PracownikSzkoly> pracownicy;

vector<PracownikSzkoly>::iterator znajdz(int id) {
	for (auto it = pracownicy.begin(); it != pracownicy.end(); it++) {
		if (it->getId() == id) {
			return it;
		}
	}
	return pracownicy.end();
}