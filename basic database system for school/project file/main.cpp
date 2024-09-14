#include"global.h"
#include"people.h"

//sets of objects required for the system to work properly
People_Manager peo;
Register reg;
char ch;
bool quit1 = false, quit2 = false;

void regConfirm();//prototype function (the main 'reConfirm' will not work properly without this)

void menu_login()//login interface
{
	system("cls");
	cout << "-------------------------" << '\n';
	cout << "         Login           " << '\n';
	cout << "-------------------------" << '\n';
	cout << "                         " << '\n';
	cout << "   [1] Student Login     " << '\n';
	cout << "                         " << '\n';
	cout << "   [2] Teacher Login     " << '\n';
	cout << "                         " << '\n';
	cout << "   [3] Staff Login       " << '\n';
	cout << "                         " << '\n';
	cout << "   [4] Back              " << '\n';
	cout << "                         " << '\n';
	cout << "-------------------------" << '\n';
	cout << "Enter your choice: ";
	cin >> ch;
	switch (ch)
	{
	case '1':
		peo.stu_oper();
		break;
	case '2':
		peo.tea_oper();
		break;
	case '3':
		peo.man_oper();
		break;
	case '4':
		system("cls");
		quit2 = true;
		break;
	default:
		cout << "Invalid option entered! Please try again" << '\n';
		system("pause");
		system("cls");
		break;
	}
}

void menu_main()//main menu interface
{
	system("cls");
	cout << "---- LM_Retro v.0.5B ----" << '\n';
	cout << "  Copyright 2023 Team_G  " << '\n';
	cout << "-------------------------" << '\n';
	cout << "        Main Menu        " << '\n';
	cout << "-------------------------" << '\n';
	cout << "                         " << '\n';
	cout << "   [1] Login             " << '\n';
	cout << "                         " << '\n';
	cout << "   [2] Register          " << '\n';
	cout << "                         " << '\n';
	cout << "   [3] Exit Program      " << '\n';
	cout << "                         " << '\n';
	cout << "-------------------------" << '\n';
	cout << "Enter your choice: ";
	cin >> ch;
	switch (ch)
	{
	case '1':
		while (!quit2) {
			menu_login();
		}quit2 = false;
		break;
	case '2':
		regConfirm();
		break;
	case '3':
		system("cls");
		cout << "\nHave a great day!" << '\n';
		system("pause");
		quit1 = true;
		break;
	default:
		cout << "Invalid option entered! Please try again" << '\n';
		system("pause");
		break;
	}
}

void regConfirm()//confirmation if the user wants to register or not
{
	system("cls");
	cout << "This will open the Registration Menu. Continue?\n\n[1] Yes\n[2] No\n";
	cin >> ch;
	switch (ch)
	{
	case '1':
		system("cls");
		reg.reg_role();
		break;
	case '2':
		menu_main();
		break;
	default:
		cout << "Invalid option entered! Please try again" << '\n';
		system("pause");
		regConfirm();
		break;
	}
}

//executes the code
int main() {
	cout << '\n';
	while (!quit1) {
		menu_main();
	}
	return 0;
}