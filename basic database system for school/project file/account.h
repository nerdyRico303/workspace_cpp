#include"global.h"

class Account
{
public:
	Account(int, string, int);
	void display();
	int account;//Account number
	string password;//Password
	int id;//Identity
};

class Student
{
public:
	Student(int, string, string, string, int, int);
	void display();
	int num;//Student number
	string name;//Name
	string grade;//Grade
	string sex;//sex
	int age;//Age
	int number;//Telephone number
};