#include "Password.h"
#include <math.h>
#include <time.h>

void Password::SetSize(int size) {
	m_Size = size;
}

void Password::SetNumbers(bool numbers) {
	m_Numbers = numbers;
}

void Password::SetLowercase(bool lowercase) {
	m_Lowercase = lowercase;
}

void Password::SetUppercase(bool upercase) {
	m_Upercase = upercase;
}

void Password::SetSpecial(bool special) {
	m_Special = special;
}

std::string Password::GeneratePassword() {

	const char symbols[7] = { '!', '@', '#', '$', '%', '^', '&' };
	const char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char letters[26];

	int j = 0;
	for (int i = 97; i < 123; i++) {
		letters[j] = i;
		j++;
	}

	srand(time(0));
	std::string placeholder = "";

	for (int i = 0; i < m_Size; i++)
	{
		if (m_Special)
			placeholder += symbols[rand() % 7];
		if (m_Numbers)
			placeholder += numbers[rand() % 10];
		if (m_Lowercase)
			placeholder += letters[rand() % 26];
		if (m_Upercase)
			placeholder += toupper(letters[rand() % 26]);
		m_password += placeholder[rand() % placeholder.size()];
	}

	return m_password;
}
