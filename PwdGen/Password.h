#pragma once

#include <string>

class Password
{
private:
	int m_Size;
	std::string m_password;
	bool m_Numbers, m_Lowercase, m_Upercase, m_Special;
public:
	Password()
		: m_Size(4), m_password(""), m_Numbers(false), m_Lowercase(true), m_Upercase(false), m_Special(false) {}
	~Password() {}
	void SetSize(int size);
	void SetNumbers(bool numbers);
	void SetLowercase(bool lowercase);
	void SetUppercase(bool upercase);
	void SetSpecial(bool special);
	std::string GeneratePassword();

};