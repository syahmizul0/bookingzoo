#include "GlobalFunctions.h"
#include "Customer.h"
#include "includes.h"
#include "CreateAccount.h"


void Login()
{
	CreateAccount user;

	char FIRSTNAME[10];
	char LASTNAME[10];
	char FULLNAME[20];
	int LENGTH;
	char USERNAME[10];
	int PASSWORD;
	std::ofstream OUTPUT;
	OUTPUT.open("information.txt");

	user.getInformation(FIRSTNAME, LASTNAME, FULLNAME);
	PASSWORD = user.Account(FULLNAME, USERNAME);
	LENGTH = user.SecurityQuestion(FULLNAME);

	std::cout << "\n\n\nPress Anything...";
	_getch();

	user.outputFile(FIRSTNAME, LASTNAME, FULLNAME, LENGTH, USERNAME, PASSWORD, &OUTPUT);

	std::cout << "\n\nNow, your privacy information will save at information.txt. \nPlease press enter again to go to our DSA ZOO SYSTEM to sign in your account :))\n\n";
	_getch();

	user.LogIn(LENGTH, PASSWORD, USERNAME, &OUTPUT);

	OUTPUT.close();
}

void Welcome()
{
	system("cls");
	std::ifstream WelcomeFile(WELCOME_FILEPATH);
	std::string line;
	if (WelcomeFile.fail())
	{
		std::cout << "\nwelcome.txt not found,exiting program\n";
		system("pause");
		exit(-1);
	}
	else
	{
		while(std::getline(WelcomeFile,line))
			std::cout << line << '\n';
		
		system("pause");
	}
	WelcomeFile.close();
	
}

void OptionScreen()
{
	system("cls");
	Customer customer;
	std::ifstream OptionFile;
	std::string line;
	int option;
	while (1)
	{
	loop:
		OptionFile.open(OPTIONS_FILEPATH);
		system("cls");
		if (OptionFile.fail())
		{
			std::cout << "\noptionmessage.txt not found,exiting program\n";
			system("pause");
			exit(-1);
		}
		else
		{
			while (std::getline(OptionFile, line))
				std::cout << line << '\n';
		}
		
		std::cout << "\nChoose your option (1,2,3) : "; std::cin >> option;

		switch (option)
		{
			case 1:	customer.Reserve(); break;
			case 2:	customer.DisplayReceipt(); break;
			case 3:	customer.ExitProgram() , exit(0); break;
			default: 
				system("cls");
				goto loop;
				break;
		}
		OptionFile.close();
	}
	
}
