#pragma once

#include <string>

using std::string;

class Employee {
protected:
	string surname;
	string id;
public:
public:
	inline Employee() : surname(""), id("") {}
	inline Employee(string surname, string id) : surname(surname), id(id) {}

	inline string getSurname() const { return surname; }
	inline string getId() const { return id; }

	inline void setSurname(string surname) { this->surname = surname; }
	inline void setId(string id) { this->id = id; }
};

class ProductionWorker : public Employee {
protected:
	int shift;
	double hourlyRate;
public:
	inline ProductionWorker() : Employee(), shift(0), hourlyRate(0) {}
	inline ProductionWorker(string surname, string id, int shift, double hourlyRate) : Employee(surname, id), shift(shift), hourlyRate(hourlyRate) {}

	inline int getShift() const { return shift; }
	inline double getHourlyRate() const { return hourlyRate; }

	inline void setShift(int shift) { this->shift = shift; }
	inline void setHourlyRate(double hourlyRate) { this->hourlyRate = hourlyRate; }
};