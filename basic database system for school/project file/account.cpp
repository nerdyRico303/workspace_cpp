#include"account.h"

Account::Account(int m_account, string m_password, int m_id)
{
	account = m_account;
	password = m_password;
	id = m_id;
}
void Account::display()
{
	if (id == 1)
	{
		cout << "\tStudent number£º" << account << endl;
		cout << "\tpassword£º" << password << endl;
	}
	else
		if (id == 2)
		{
			cout << "\tTeacher account£º" << account << endl;
			cout << "\tpassword£º" << password << endl;
		}
		else
			if (id == 3)
			{
				cout << "\tAdmin account£º" << account << endl;
				cout << "\tpassword£º" << password << endl;
			}
}

Student::Student(int m_num, string m_name, string m_grade, string m_sex, int m_age, int m_number)
{
	this->num = m_num;
	this->name = m_name;
	this->grade = m_grade;
	this->sex = m_sex;
	this->age = m_age;
	this->number = m_number;
}

void Student::display()
{
	cout << "Student Number:" << this->num << '\n';
	cout << "Name:" << this->name << '\n';
	cout << "Grade:" << this->grade << '\n';
	cout << "Gender:" << this->sex << '\n';
	cout << "Age:" << this->age << '\n';
	cout << "Phone Number:" << this->number << '\n';
}