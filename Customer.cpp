#include "Customer.h"
#include "includes.h"
Customer::Customer()
{

}

Customer::~Customer()
{

}

void Customer::Reserve()
{
	std::ifstream PricingFile;
	std::string line;
	int numOfTickets;
	int ticketType;
	char moretickettype;
	char editnewdate;
	static int counting = 0;
	start:
	system("cls");
	PricingFile.open(PRICING_FILEPATH);
	if (PricingFile.fail())
	{
		std::cout << "\npricing.txt not found,exiting program\n";
		system("pause");
		exit(-1);
	}
	else
	{
		while (std::getline(PricingFile, line))
			std::cout << line << '\n';
	}
	PricingFile.close();
	askagain:
	std::cout << "Enter the ticket type that you want(1-6) : "; std::cin >> ticketType;
	std::cout << "Enter the number of tickets you want : "; std::cin >> numOfTickets;
	std::cin.ignore();
	for (int i = 0; i < numOfTickets; i++)
	{
		Customer* ticketcust = new Customer;
		ticketcust->TicketInput();
		switch (ticketType)
		{
			case 1:ticketcust->customerType = "Adult"; ticketcust->pricing = 38; break;
			case 2:ticketcust->customerType = "Senior Citizen"; ticketcust->pricing = 31; break;
			case 3:ticketcust->customerType = "Children"; ticketcust->pricing = 29; break;
			case 4:ticketcust->customerType = "Senior Citizen"; ticketcust->nationality = "Foreigner"; ticketcust->pricing = 50; break;
			case 5:ticketcust->customerType = "Adult"; ticketcust->nationality = "Foreigner"; ticketcust->pricing = 81; break;
			case 6:ticketcust->customerType = "Children"; ticketcust->nationality = "Foreigner"; ticketcust->pricing = 59; break;
			default:goto askagain; break;
		}
		this->guestslist.push_back(ticketcust);
	}
	
	std::cout << std::endl;
	std::cout << "Do you want to add another ticket type?(y/n) : "; std::cin >> moretickettype;
	if (moretickettype == 'y')
		goto start;
	if (moretickettype = 'n' && counting > 0)
	{
		std::cout << " Do you want to input new date or not? (y/n) : ";
		std::cin >> editnewdate;

		if (editnewdate == 'n')
			goto start;
	}
	std::cout << "Enter the date you want to book (in numbers) : \n";
	std::cout << "Enter the day : "; std::cin >> this->dateofbooking[0];
	std::cout << "Enter the month : "; std::cin >> this->dateofbooking[1];
	std::cout << "Enter the year : "; std::cin >> this->dateofbooking[2];
	counting++;
}

void Customer::TicketInput()
{
	static int count = 1;
	
	system("cls");
	std::cout << "Enter info for ticket " << count << " : \n";
	std::cout << "Enter name : "; 
 	std::getline(std::cin, this->name);
	
	count++;
}

void Customer::VariableCounter(std::vector<std::array<std::string, 2>> *array) 
{
	std::vector<std::string>tempstrarr;
	
	if (!this->guestslist.empty())
	{
		for (size_t i = 0; i < this->guestslist.size(); ++i)
		{
			tempstrarr.push_back(this->guestslist.at(i)->nationality + " " + this->guestslist.at(i)->customerType);
		}
	}

	int numOfType[100]= {}; 
	std::string strOfType[100] = {};
	int count = 0;
	if (!tempstrarr.empty())
	{
		for (size_t i = 0; i < tempstrarr.size(); i++)
		{
			count = 0;
			for (size_t j = 0; j < tempstrarr.size(); j++)
			{
				if (tempstrarr.at(i) == tempstrarr.at(j))
				{
					count++;
				}
			}
			numOfType[i] = count;
			strOfType[i] = tempstrarr.at(i);
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int k = i + 1; k < 100; k++)
		{
			if (strOfType[i] != "") 
			{
				if (strOfType[i] == strOfType[k])
				{
					numOfType[k] = 0;
					strOfType[k] = "";
				}
			}
			}
			
	}
	for (int i = 0; i < 100; i++)
	{
		if (numOfType[i] != 0 && strOfType[i] != "")
		{
			std::array <std::string,2> str = { std::to_string(numOfType[i]), strOfType[i] };
			array->push_back(str);
		}
	}
}

void Customer::DisplayReceipt()
{
	std::vector<std::array<std::string, 2>>array;
	VariableCounter(&array);

	system("cls");
	std::cout << "\nYour booking date : \n";
	std::cout << "Day : " << this->dateofbooking[0] << "\n"<< "Month : " << this->dateofbooking[1] << "\n" << "Year : " << this->dateofbooking[2] << std::endl;
	if (!this->guestslist.empty())
	{
		std::cout << "\nTicket Infos:\n\n";
		for (size_t k = 0; k < array.size(); k++)
		{
			std::cout << array.at(k)[1] << " - " << array.at(k)[0] << std::endl;
			for (size_t i = 0; i < this->guestslist.size(); ++i)
			{
				if (this->guestslist.at(i)->nationality + " " + this->guestslist.at(i)->customerType == array.at(k)[1])
				{
					std::cout <<this->guestslist.at(i)->name << std::endl;
				}
				/*std::cout << std::endl;
				std::cout << "Name of guest " << i + 1 << " : " << this->guestslist.at(i)->name << std::endl;
				std::cout << "Ticket Type : " << this->guestslist.at(i)->nationality << " " << this->guestslist.at(i)->customerType << std::endl;
				std::cout << std::endl;*/
			}
		}
		
	}
	system("pause");
}

void Customer::InsertionSort(std::string name[], int n)
{
	int i, key, j;
	std::string key2;
	for (i = 1; i < n; i++)
	{
		key = (int)name[i].front();
		key2 = name[i];
		j = i - 1;
		while (j >= 0 && key < (int)name[j].front())
		{
			name[j + 1] = name[j];
			j = j - 1;
		}
		name[j + 1] = key2;
	}
}

void Customer::ExitProgram()
{
	static int count = 1;

	system("cls");
	std::cout << "\nThank You For Choosing Zoo Booking System :)\n";
	std::getline(std::cin, this->name);

	count++;
}
