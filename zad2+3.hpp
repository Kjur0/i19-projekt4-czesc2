/**
 * @file zad2+3.hpp
 * @brief Contains the declaration of classes and enums related to school employees.
 */
#pragma once

#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

/**
 * @enum Stanowisko
 * @brief Represents the position of a school employee.
 */
enum Stanowisko {
	Nauczyciel, /**< Teacher */
	Dyrektor, /**< Principal */
	Sekretarka, /**< Secretary */
	Wychowawca /**< Tutor */
};
/**
 * @var Stanowiska
 * @brief Array of strings representing the names of the positions.
 */
string Stanowiska[] = {
	"Nauczyciel",
	"Dyrektor",
	"Sekretarka",
	"Wychowawca"
};

/**
 * @class PracownikSzkoly
 * @brief Represents a school employee.
 */
class PracownikSzkoly {
protected:
	int id; /**< Employee ID */
	string imie; /**< First name */
	string nazwisko; /**< Last name */
	double stawka; /**< Hourly rate */
	int godziny; /**< Weekly hours */
	Stanowisko stanowisko; /**< Position */
public:
	/**
	 * @brief Constructs a new PracownikSzkoly object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 * @param stanowisko The position.
	 */
	PracownikSzkoly(int id, string imie, string nazwisko, double stawka, int godziny, Stanowisko stanowisko) : id(id), imie(imie), nazwisko(nazwisko), stawka(stawka), godziny(godziny), stanowisko(stanowisko) {}
	/**
	 * @brief Constructs a new PracownikSzkoly object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 * @param stanowisko The position as a string.
	 */
	PracownikSzkoly(int id, string imie, string nazwisko, double stawka, int godziny, string stanowisko) : id(id), imie(imie), nazwisko(nazwisko), stawka(stawka), godziny(godziny) { setStanowisko(stanowisko); }

	/**
	 * @brief Gets the employee ID.
	 * @return The employee ID.
	 */
	int getId() const { return id; }
	/**
	 * @brief Gets the first name.
	 * @return The first name.
	 */
	string getImie() const { return imie; }
	/**
	 * @brief Gets the last name.
	 * @return The last name.
	 */
	string getNazwisko() const { return nazwisko; }
	/**
	 * @brief Gets the hourly rate.
	 * @return The hourly rate.
	 */
	double getStawka() const { return stawka; }
	/**
	 * @brief Gets the weekly hours.
	 * @return The weekly hours.
	 */
	int getGodziny() const { return godziny; }
	/**
	 * @brief Gets the position.
	 * @return The position as a string.
	 */
	string getStanowisko() const {
		return Stanowiska[stanowisko];
	}
	/**
	 * @brief Gets the weekly salary.
	 * @return The weekly salary.
	 */
	double getWynagrodzenie() const { return stawka * godziny; }

	/**
	 * @brief Sets the hourly rate.
	 * @param stawka The new hourly rate.
	 */
	void setStawka(double stawka) { this->stawka = stawka; }
	/**
	 * @brief Sets the weekly hours.
	 * @param godziny The new weekly hours.
	 */
	void setGodziny(int godziny) { this->godziny = godziny; }
	/**
	 * @brief Sets the position.
	 * @param stanowisko The new position.
	 */
	void setStanowisko(Stanowisko stanowisko) { this->stanowisko = stanowisko; }
	/**
	 * @brief Sets the position.
	 * @param stanowisko The new position as a string.
	 */
	void setStanowisko(string stanowisko) {
		for (int i = 0; i < 4; i++) {
			if (stanowisko == Stanowiska[i]) {
				this->stanowisko = (Stanowisko)i;
			}
		}
	}

	/**
	 * @brief Prints the employee information.
	 */
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

/**
 * @enum Przedmiot
 * @brief Represents a school subject.
 */
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
/**
 * @var Przedmioty
 * @brief Array of strings representing the names of the subjects.
 */
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

/**
 * @class Nauczyciel
 * @brief Represents a teacher, derived from PracownikSzkoly.
 */
class Nauczyciel : public PracownikSzkoly {
	Przedmiot przedmiot; /**< Taught subject */
public:
	/**
	 * @brief Constructs a new Nauczyciel object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 * @param przedmiot The taught subject.
	 */
	Nauczyciel(int id, string imie, string nazwisko, double stawka, int godziny, Przedmiot przedmiot) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Nauczyciel), przedmiot(przedmiot) {}
	/**
	 * @brief Constructs a new Nauczyciel object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 * @param przedmiot The taught subject as a string.
	 */
	Nauczyciel(int id, string imie, string nazwisko, double stawka, int godziny, string przedmiot) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Nauczyciel) { setPrzedmiot(przedmiot); }

	/**
	 * @brief Gets the taught subject.
	 * @return The taught subject as a string.
	 */
	string getPrzedmiot() const {
		return Przedmioty[przedmiot];
	}

	/**
	 * @brief Sets the taught subject.
	 * @param przedmiot The new taught subject.
	 */
	void setPrzedmiot(Przedmiot przedmiot) { this->przedmiot = przedmiot; }

	/**
	 * @brief Sets the taught subject.
	 * @param przedmiot The new taught subject as a string.
	 */
	void setPrzedmiot(string przedmiot) {
		for (int i = 0; i < 17; i++) {
			if (przedmiot == Przedmioty[i]) {
				this->przedmiot = (Przedmiot)i;
			}
		}
	}

	/**
	 * @brief Prints the teacher's information.
	 */
	void print() const {
		PracownikSzkoly::print();
		cout << "\tNauczany przedmiot: " << getPrzedmiot() << endl;
	}
};

/**
 * @class Dyrektor
 * @brief Represents a principal, derived from PracownikSzkoly.
 */
class Dyrektor : public PracownikSzkoly {
public:
	/**
	 * @brief Constructs a new Dyrektor object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 */
	Dyrektor(int id, string imie, string nazwisko, double stawka, int godziny) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Dyrektor) {}
};

/**
 * @class Sekretarka
 * @brief Represents a secretary, derived from PracownikSzkoly.
 */
class Sekretarka : public PracownikSzkoly {
public:
	/**
	 * @brief Constructs a new Sekretarka object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 */
	Sekretarka(int id, string imie, string nazwisko, double stawka, int godziny) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Sekretarka) {}
};

/**
 * @class Wychowawca
 * @brief Represents a tutor, derived from PracownikSzkoly.
 */
class Wychowawca : public PracownikSzkoly {
private:
	string klasa; /**< Tutored class */
public:
	/**
	 * @brief Constructs a new Wychowawca object.
	 * @param id The employee ID.
	 * @param imie The first name.
	 * @param nazwisko The last name.
	 * @param stawka The hourly rate.
	 * @param godziny The weekly hours.
	 * @param klasa The tutored class.
	 */
	Wychowawca(int id, string imie, string nazwisko, double stawka, int godziny, string klasa) : PracownikSzkoly(id, imie, nazwisko, stawka, godziny, Stanowisko::Wychowawca), klasa(klasa) {}

	/**
	 * @brief Gets the tutored class.
	 * @return The tutored class.
	 */
	string getKlasa() const { return klasa; }

	/**
	 * @brief Sets the tutored class.
	 * @param klasa The new tutored class.
	 */
	void setKlasa(string klasa) { this->klasa = klasa; }

	/**
	 * @brief Prints the tutor's information.
	 */
	void print() const {
		PracownikSzkoly::print();
		cout << "\tWychowywana klasa: " << getKlasa() << endl;
	}
};

vector<PracownikSzkoly> pracownicy; /**< Vector of school employees */

/**
 * @brief Finds an employee by ID.
 * @param id The employee ID.
 * @return An iterator pointing to the found employee, or pracownicy.end() if not found.
 */
vector<PracownikSzkoly>::iterator znajdz(int id) {
	for (auto it = pracownicy.begin(); it != pracownicy.end(); it++) {
		if (it->getId() == id) {
			return it;
		}
	}
	return pracownicy.end();
}