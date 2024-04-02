/**
 * @file zad1.hpp
 * @brief Contains the declaration of classes related to production workers.
 */
#pragma once

#include <string>

using std::string;

/**
 * @class Employee
 * @brief Represents an employee with a surname and an ID.
 *
 * The Employee class provides functionality to store and retrieve information about an employee,
 * including their surname and ID.
 */
class Employee {
protected:
	string surname; /**< The surname of the employee. */
	string id; /**< The ID of the employee. */
public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the surname and ID of the employee to empty strings.
	 */
	inline Employee() : surname(""), id("") {}
	/**
	 * @brief Parameterized constructor.
	 *
	 * Initializes the surname and ID of the employee with the given values.
	 *
	 * @param surname The surname of the employee.
	 * @param id The ID of the employee.
	 */
	inline Employee(string surname, string id) : surname(surname), id(id) {}

	/**
	 * @brief Get the surname of the employee.
	 *
	 * @return The surname of the employee.
	 */
	inline string getSurname() const { return surname; }
	/**
	 * @brief Get the ID of the employee.
	 *
	 * @return The ID of the employee.
	 */
	inline string getId() const { return id; }

	/**
	 * @brief Set the surname of the employee.
	 *
	 * @param surname The surname of the employee.
	 */
	inline void setSurname(string surname) { this->surname = surname; }
	/**
	 * @brief Set the ID of the employee.
	 *
	 * @param id The ID of the employee.
	 */
	inline void setId(string id) { this->id = id; }
};

/**
 * @class ProductionWorker
 * @brief Represents a production worker who is an employee.
 *
 * The ProductionWorker class is a derived class of the Employee class.
 * It represents a production worker who has a shift and an hourly rate.
 */
class ProductionWorker : public Employee {
protected:
	int shift; /**< The shift of the production worker. */
	double hourlyRate; /**< The hourly rate of the production worker. */
public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the ProductionWorker object with default values.
	 */
	inline ProductionWorker() : Employee(), shift(0), hourlyRate(0) {}
	/**
	 * @brief Parameterized constructor.
	 *
	 * Initializes the ProductionWorker object with the specified values.
	 *
	 * @param surname The surname of the production worker.
	 * @param id The ID of the production worker.
	 * @param shift The shift of the production worker.
	 * @param hourlyRate The hourly rate of the production worker.
	 */
	inline ProductionWorker(string surname, string id, int shift, double hourlyRate) : Employee(surname, id), shift(shift), hourlyRate(hourlyRate) {}

	/**
	 * @brief Get the shift of the production worker.
	 *
	 * @return The shift of the production worker.
	 */
	inline int getShift() const { return shift; }
	/**
	 * @brief Get the hourly rate of the production worker.
	 *
	 * @return The hourly rate of the production worker.
	 */
	inline double getHourlyRate() const { return hourlyRate; }

	/**
	 * @brief Set the shift of the production worker.
	 *
	 * @param shift The shift of the production worker.
	 */
	inline void setShift(int shift) { this->shift = shift; }
	/**
	 * @brief Set the hourly rate of the production worker.
	 *
	 * @param hourlyRate The hourly rate of the production worker.
	 */
	inline void setHourlyRate(double hourlyRate) { this->hourlyRate = hourlyRate; }
};