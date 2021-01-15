#pragma once
#include "includes.h"
class Customer {
public:
	Customer();
	~Customer();
	void Reserve();
	void TicketInput();
	void VariableCounter(std::vector<std::array<std::string, 2>>* array); //counts how many customer types there are and store it in a vector
	void DisplayReceipt();
	void InsertionSort(std::string name[], int n); //modified version of insertion sort from https://www.geeksforgeeks.org/insertion-sort/
	void ExitProgram();

private:
	std::string name;
	std::vector <Customer*> guestslist;
	std::string customerType;
	int dateofbooking[3]; 
	float pricing;
	std::string nationality;
};
