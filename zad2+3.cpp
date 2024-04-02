#include "zad2+3.hpp"

using namespace std;

void dodaj() {
	cout << endl << endl;
	char cont;
	do {
		cout << "Dodaj pracownika:" << endl;
		int id = pracownicy.size() + 1;

		Stanowisko Stanowisko;
		{
			int tmp;
			cout << "\t(0) Nauczyciel, (1) Dyrektor, (2) Sekretarka, (3) Wychowawca" << endl;
			cout << "\tPodaj stanowisko: ";
			cin >> tmp;
			Stanowisko = (enum Stanowisko)tmp;
		}

		string imie, nazwisko;
		double stawka;
		int godziny;

		cout << "\tPodaj imię: ";
		cin >> imie;

		cout << "\tPodaj nazwisko: ";
		cin >> nazwisko;

		cout << "\tPodaj stawkę: ";
		cin >> stawka;

		cout << "\tPodaj ilość godzin: ";
		cin >> godziny;

		PracownikSzkoly pracownik(id, imie, nazwisko, stawka, godziny, Stanowisko);
		pracownicy.push_back(pracownik);
		cout << endl << "Pracownik dodany..." << endl << endl;

		cout << "Czy chcesz dodać kolejnego pracownika? (t/n): ";
		cin >> cont;
	} while (cont == 't' || cont == 'T');
}
void usun() {
	cout << endl << endl;
	char cont;
	do {
		cout << "Usuń pracownika:" << endl;

		int id;
		cout << "\tPodaj id pracownika do usunięcia: ";
		cin >> id;

		cout << endl;

		auto it = znajdz(id);
		if (it != pracownicy.end()) {
			pracownicy.erase(it);
			cout << "Pracownik usunięty...";
		} else {
			cout << "Pracownik nie istnieje...";
		}

		cout << endl << endl << "Czy chcesz usunąć kolejnego pracownika? (t/n): ";
		cin >> cont;
	} while (cont == 't' || cont == 'T');
}
void wyswietl() {
	cout << endl << endl;
	cout << "Pracownicy:" << endl;
	for (auto it = pracownicy.begin(); it != pracownicy.end(); it++) {
		it->print();
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "pl_PL.utf8");
	while (true) {
		cout << "Menu:" << endl;
		cout << "\t1. Dodaj pracownika" << endl;
		cout << "\t2. Usuń pracownika" << endl;
		cout << "\t3. Wyświetl pracowników" << endl;
		cout << "\t4. Wyjdź" << endl;
		int wybor;
		cout << "Wybierz opcję: ";
		cin >> wybor;
		switch (wybor) {
		case 1:
			dodaj();
			break;
		case 2:
			usun();
			break;
		case 3:
			wyswietl();
			break;
		case 4:
			return 0;
		}
	}
}