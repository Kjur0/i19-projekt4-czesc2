#include "zad1.hpp"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "pl_PL.utf8");

	ProductionWorker pw;

	{
		string tmpString;
		int tmpInt;

		cout << "<-podaj nazwisko: ";
		cin >> tmpString;
		pw.setSurname(tmpString);

		cout << "<-podaj id: ";
		cin >> tmpString;
		pw.setId(tmpString);

		cout << "<-podaj zmianę: ";
		cin >> tmpInt;
		pw.setShift(tmpInt);

		cout << "<-podaj stawkę godzinową: ";
		cin >> tmpInt;
		pw.setHourlyRate(tmpInt);
	}

	cout << endl << endl << endl;

	cout << "->Nazwisko: " << pw.getSurname() << endl;
	cout << "->Id: " << pw.getId() << endl;
	cout << "->Zmiana: " << pw.getShift() << endl;
	cout << "->Stawka godzinowa: " << pw.getHourlyRate() << endl;
}