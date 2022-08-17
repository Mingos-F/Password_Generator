#include "Password.h"
#include <iostream>

void PrintMenu();
void SetParams(Password& p);

int main() {

	char key = '0';


	do {
		system("cls");
		PrintMenu();
		std::cin >> key;
		if (key != '1' && key != '2') {
			system("cls");
			PrintMenu();
		}

		if (key == '1') {
			system("cls");
			Password p;
			SetParams(p);
			std::cout << "Your password is: " << p.GeneratePassword() << std::endl;
			std::cout << "Press Enter key ...." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}

	} while (key != '2');

}

void PrintMenu() {
	std::cout << "Welcome to the Password Generator" << std::endl;
	std::cout << "1 - Create a password" << std::endl;
	std::cout << "2 - Exit program" << std::endl;
}

void SetParams(Password& p) {

	int s = 0;
	char input = '\0';

	bool fail;

	p.SetLowercase(true);

	do {
		system("cls");
		std::cout << "Lenght of the password?" << std::endl;
		std::cin >> s;

		fail = std::cin.fail();

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (fail || s <=0);

	p.SetSize(s);
	std::cout << "Include symbols? (y = yes / other key = no)" << std::endl;
	std::cin >> input;
	if (input == 'y')
		p.SetSpecial(true);
	else
		p.SetSpecial(false);

	std::cout << "Include numbers? (y = yes / other key = no)" << std::endl;
	std::cin >> input;
	if (input == 'y')
		p.SetNumbers(true);
	else
		p.SetNumbers(false);

	std::cout << "Include upper characters? (y = yes / other key = no)" << std::endl;
	std::cin >> input;
	if (input == 'y')
		p.SetUppercase(true);
	else
		p.SetUppercase(false);
}