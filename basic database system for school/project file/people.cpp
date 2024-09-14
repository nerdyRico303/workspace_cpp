#include"people.h"

void People_Manager::stu_init()//initialisation
{
	fstream f;
	f.open(FILENAME1, ios::in);
	int m_num;
	string m_name;
	string m_grade;
	string m_sex;
	int m_age;
	int m_number;

	int  i = 0;
	//read
	while (f >> m_num && f >> m_name && f >> m_grade && f >> m_sex && f >> m_age && f >> m_number)
	{
		Student* stu = NULL;
		stu = new Student(m_num, m_name, m_grade, m_sex, m_age, m_number);
		M_Student[i] = stu;
		i++;
	}
	f.close();
}

int People_Manager::stu_num()//Initialisation Quantity
{
	fstream f;
	f.open(FILENAME1, ios::in);
	int i = 0;
	int m_num;
	string m_name;
	string m_grade;
	string m_sex;
	int m_age;
	int m_number;
	while (f >> m_num && f >> m_name && f >> m_grade && f >> m_sex && f >> m_age && f >> m_number)
	{
		i++;
	}
	f.close();
	return i;
}

void People_Manager::acc_init()//Account Initialisation
{
	fstream f;
	f.open(FILENAME2, ios::in);
	int account;
	string password;
	int id;
	int  i = 0;
	while (f >> account && f >> password && f >> id)
	{
		Account* Acc = NULL;
		Acc = new Account(account, password, id);
		M_Account[i] = Acc;
		i++;
	}
	f.close();
}

void People_Manager::stu_show()//Show Students
{
	for (int i = 0; i < Stu_Num; i++)
	{
		M_Student[i]->display();
	}
	system("pause");
	system("cls");
}

void People_Manager::stu_add()//Add Student
{
	fstream f;
	f.open(FILENAME2, ios::out);
	if (!f.is_open())
	{
		cout << "File does not exist" << endl;
		return;
	}
	int j;
	int num;
	cout << "Please enter the number of students to be added:" << endl;
	cin >> num;
	Account** Acc_Manager = new Account * [Acc_Num + num];
	int i;
	for (i = 0; i < Acc_Num; i++)
	{
		Acc_Manager[i] = M_Account[i];
	}
	j = i;
	int account;
	string password;
	//Create a new array with more space
	Student** E_Student;
	E_Student = new Student * [Stu_Num + num];
	//Copying arrays
	for (i = 0; i < Stu_Num; i++)
	{
		E_Student[i] = M_Student[i];
	}
	int id;
	int m_num;
	string m_name;
	string m_grade;
	string m_sex;
	int m_age;
	int m_number;

	for (i = 0; i < num; i++)
	{
		int flag = 0;
		Account* acc = NULL;
		Student* stu = NULL;
		cout << "Please enter the " << i + 1 << "A student's school number:" << endl;
		cin >> m_num;
		//Determine if there are duplicates
		for (int jjj = 0; jjj < Stu_Num; jjj++)
		{
			if (M_Student[jjj]->num == m_num)
			{
				cout << "This student already exists, please re-enter..." << endl;
				system("pause");
				system("cls");
				flag = 1;
				i--;
				break;
			}
		}
		if (flag == 1)
		{
			continue;
		}
		cout << "Please enter the number of" << i + 1 << "Names of students£º" << endl;
		cin >> m_name;
		cout << "Please enter the number of" << i + 1 << "A student's age:" << endl;
		cin >> m_grade;
		cout << "Please enter the number of" << i + 1 << "The gender of the students:" << endl;
		cin >> m_sex;
		cout << "Please enter the number of" << i + 1 << "age of the individual students:" << endl;
		cin >> m_age;
		cout << "Please enter the number of" << i + 1 << "A student's phone number:" << endl;
		cin >> m_number;
		//The default password is 666666
		acc = new Account(m_num, "666666", 1);
		Acc_Manager[j] = acc;
		stu = new Student(m_num, m_name, m_grade, m_sex, m_age, m_number);
		E_Student[i + Stu_Num] = stu;
		j++;
	}
	//Release of previously opened space
	delete[] M_Student;
	delete[] M_Account;

	M_Account = Acc_Manager;
	M_Student = E_Student;
	//quantity plus
	Stu_Num += num;
	Acc_Num += num;

	cout << "Successfully added" << num << "student" << endl;

	f.close();

	stu_save();
	account_save();

	system("pause");
	system("cls");
}

void People_Manager::stu_save()//Keeping students
{
	fstream f;
	f.open(FILENAME1, ios::out);
	for (int i = 0; i < Stu_Num; i++)
	{
		f << M_Student[i]->num << " "
			<< M_Student[i]->name << " "
			<< M_Student[i]->grade << " "
			<< M_Student[i]->sex << " "
			<< M_Student[i]->age << " "
			<< M_Student[i]->number << endl;
	}
	f.close();
}

void People_Manager::stu_del()//Delete Student
{
	int num;
	string name;
	int id;
	cout << "Enter the student number and name of the deleted student" << endl;
	cin >> num;
	cin >> name;
	for (int i = 0; i < Stu_Num; i++)
	{
		if (M_Student[i]->num == num && M_Student[i]->name == name)
		{
			for (int j = i; j < Stu_Num; j++)
			{
				M_Student[j] = M_Student[j + 1];
			}
			cout << "Deleted successfully" << endl;

			Stu_Num--;

			break;
		}
	}
	for (int k = 0; k < Acc_Num; k++)
	{
		if (M_Account[k]->account == num)
		{
			for (int j = k; j < Acc_Num; j++)
			{
				M_Account[k] = M_Account[k + 1];
			}
		}
	}
	//Volume minus one
	Acc_Num--;
	stu_save();
	account_save();
	system("pause");
	system("cls");
}

void People_Manager::stu_mod()//Modification of students
{
	int num;
	string name;
	int id;
	int j;
	int i = 0;
	cout << "Enter the modified student number and name" << endl;
	cin >> num;
	cin >> name;
	for (; i < Stu_Num; i++)
	{
		if (M_Student[i]->num == num && M_Student[i]->name == name)
		{
			j = i;
			break;
		}
	}
	if (i == Stu_Num)
	{
		cout << "lit. cannot find this person" << endl;
		return;
	}
	int k;
	int m_num;
	string m_name;
	string m_grade;
	string m_sex;
	int m_age;
	int m_number;
	while (true)
	{
		int ch;
		cout << "1.student number" << endl;
		cout << "2. Name" << endl;
		cout << "3. Grades" << endl;
		cout << "4. Gender" << endl;
		cout << "5. Age" << endl;
		cout << "6. Telephone numbers" << endl;
		cout << "7. All" << endl;
		cout << "0. return" << endl;
		cout << "Please enter the part to be modified£º" << endl;

		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter your new student number£º" << endl;
			for (int i = 0; i < Acc_Num; i++)
			{
				if (M_Account[i]->account == m_num)
				{
					k = i;
					break;
				}
			}
			cin >> m_num;
			M_Student[j]->num = m_num;
			M_Account[k]->account = m_num;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Enter a new name:" << endl;
			cin >> m_name;
			M_Student[j]->name = m_name;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Enter the new grade level:" << endl;
			cin >> m_grade;
			M_Student[j]->grade = m_grade;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Enter the new gender:" << endl;
			cin >> m_sex;
			M_Student[j]->sex = m_sex;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Enter the new age:" << endl;
			cin >> m_age;
			M_Student[j]->age = m_age;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Enter the new phone number:" << endl;
			cin >> m_number;
			M_Student[j]->number = m_number;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			for (int i = 0; i < Acc_Num; i++)
			{
				if (M_Account[i]->account == m_num)
				{
					k = i;
					break;
				}
			}
			cout << "Enter the new school number:" << endl;
			cin >> m_num;
			M_Student[j]->num = m_num;
			M_Account[k]->account = m_num;
			cout << "Enter a new name:" << endl;
			cin >> m_name;
			M_Student[j]->name = m_name;
			cout << "Enter the new grade level:" << endl;
			cin >> m_grade;
			M_Student[j]->grade = m_grade;
			cout << "Enter the new gender:" << endl;
			cin >> m_sex;
			M_Student[j]->sex = m_sex;
			cout << "Enter the new age:" << endl;
			cin >> m_age;
			M_Student[j]->age = m_age;
			cout << "Enter the new phone number:" << endl;
			cin >> m_number;
			M_Student[j]->number = m_number;
			cout << "Modified successfully" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			stu_save();
			return;
			break;
		}
	}

}

void People_Manager::stu_find()//Find a Student
{

	int num;
	string name;
	int j, i;
	cout << "Enter the student number and name of the student you are looking for" << endl;
	cin >> num;
	cin >> name;
	for (i = 0; i < Stu_Num; i++)
	{
		if (M_Student[i]->num == num && M_Student[i]->name == name)
		{
			j = i;
			cout << M_Student[j]->num << " " <<
				M_Student[j]->name << " " <<
				M_Student[j]->grade << " " <<
				M_Student[j]->sex << " " <<
				M_Student[j]->age << " " <<
				M_Student[j]->number << endl;
			break;
		}
	}
	if (i == Stu_Num)
	{
		cout << "lit. cannot find this person" << endl;
	}
	system("pause");
	system("cls");

}

void  People_Manager::stu_oper()//operation
{
	int account;
	string password;
	while (true)
	{
		cout << "Enter your student username:" << '\n';
		cin >> account;
		cout << "Enter your password:" << '\n';
		pass_au(password);
		int flag = 0;
		int j;
		char b;
		for (int k = 0; k < Acc_Num; k++)
		{
			if (M_Account[k]->account == account && M_Account[k]->password == password && M_Account[k]->id == 1)
			{
				flag = 1;
				j = k;
				cout << "Login Successful" << '\n';
				system("pause");
				system("cls");
				break;
			}
		}
		if (flag)
		{
			int c;
			while (true)
			{
				cout << "\t\t------------------------------" << endl;
				cout << "\t\t|1. View your own information|" << endl;
				cout << "\t\t------------------------------" << endl;
				cout << "\t\t|2. Change password          |" << endl;
				cout << "\t\t------------------------------" << endl;
				cout << "\t\t|0. Return                   |" << endl;
				cout << "\t\t------------------------------" << endl;
				cin >> c;
				switch (c)
				{
				case 1:
					for (int k = 0; k < Stu_Num; k++)
					{
						if (M_Student[k]->num == account)
						{
							M_Student[k]->display();
							system("pause");
							system("cls");
							break;
						}
					}
					break;
				case 2:
					cout << "Enter the new password:" << endl;
					cin >> password;
					M_Account[j]->password = password;
					account_save();
					cout << "Modified successfully" << endl;
					system("pause");
					system("cls");
					break;
				case 0:
					system("cls");
					return;
					break;
				}
			}
		}
		else
		{
			cout << "incorrect password" << endl;
			cout << "Whether to re-enter....(y/n)" << endl;
			cin >> b;
			if (b == 'n')
			{
				system("cls");
				return;
			}
			system("cls");
		}
	}
}

void People_Manager::tea_oper()//Teacher operation
{
	int account;
	string password;
	while (true)
	{
		cout << "Enter the your ID number:" << endl;
		cin >> account;
		cout << "Enter password:" << endl;
		//cin >> password;
		int flag = 0;
		pass_au(password);
		int j;
		for (int k = 0; k < Acc_Num; k++)
		{
			if (M_Account[k]->id == 2 && M_Account[k]->account == account && M_Account[k]->password == password)
			{
				flag = 1;
				j = k;
				cout << "Login Successful" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		if (flag)
		{
			int c;
			while (true)
			{
				cout << "\t\t----------------------------------" << endl;
				cout << "\t\t|1. View all student info        |" << endl;
				cout << "\t\t----------------------------------" << endl;
				cout << "\t\t|2. View individual student info |" << endl;
				cout << "\t\t----------------------------------" << endl;
				cout << "\t\t|3. Change password              |" << endl;
				cout << "\t\t----------------------------------" << endl;
				cout << "\t\t|0. Return                       |" << endl;
				cout << "\t\t----------------------------------" << endl;
				cin >> c;
				int flag2 = 0;
				switch (c)
				{
				case 1:
					for (int k = 0; k < Stu_Num; k++)
					{
						M_Student[k]->display();
					}
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "Enter the student's student number:" << endl;
					cin >> account;
					for (int k = 0; k < Stu_Num; k++)
					{
						if (M_Student[k]->num == account)
						{
							flag2 = 1;
							M_Student[k]->display();
							system("pause");
							system("cls");
							break;
						}
					}
					if (!flag2)
					{
						cout << "lit. cannot find this person" << endl;
					}
					break;
				case 3:
					cout << "Enter the new password:" << endl;
					cin >> password;
					M_Account[j]->password = password;
					account_save();
					break;
				case 0:
					system("cls");
					return;
					break;
				}
				system("cls");
			}
		}
		else
		{
			char b;
			cout << "incorrect password" << endl;
			cout << "Whether to re-enter....(y/n)" << endl;
			cin >> b;
			if (b == 'n')
			{
				system("cls");
				return;
			}
			system("cls");
		}
	}
}

void  People_Manager::account_save()//Account Saving
{
	fstream f;
	f.open(FILENAME2, ios::out);
	if (!f.is_open())
	{
		cout << "File does not exist" << endl;
		return;
	}
	for (int i = 0; i < Acc_Num; i++) {
		f << M_Account[i]->account << " " <<
			M_Account[i]->password << " " <<
			M_Account[i]->id << " " << endl;
	}
	f.close();
}

void People_Manager::man_oper()//Administrator operation
{

	int number = 3;
	int ACCOUNT;
	string PASSWORD;
	string password;
	int id;
	int account;
	while (true)
	{

		if (number == 3)
		{
			cout << "Please enter an account number:" << endl;
			cin >> ACCOUNT;
		}
		cout << "Please enter your password:" << endl;
		pass_au(PASSWORD);
		int FLAG = 0;
		for (int ii = 0; ii < Acc_Num; ii++)
		{
			if (M_Account[ii]->account == ACCOUNT && M_Account[ii]->id == 3 && M_Account[ii]->password == PASSWORD)
			{
				FLAG = 1;
				break;
			}
		}
		if (FLAG)
		{
			cout << "Login Successful...." << endl;
			system("pause");
			system("cls");
			//
			int ch;
			int f;
			while (true)
			{

				int flag = 0;
				cout << "\t\t --------------------" << endl;
				cout << "\t\t|1. Operation of student information  |" << endl;
				cout << "\t\t --------------------" << endl;
				cout << "\t\t|2¡¢ Account Operation     |" << endl;
				cout << "\t\t --------------------" << endl;
				cout << "\t\t|0. Logging out     |" << endl;
				cout << "\t\t --------------------" << endl;
				cout << "Enter your choices:" << endl;
				cin >> ch;
				system("cls");
				switch (ch)
				{
				case 1:
					//
					while (true)
					{
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|1. Additional students   |" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|2. Deletion of students   |" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|3. Modification of student information|" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|4. Finding students  |" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|5. Displaying student information|" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|6. Sorting students    |" << endl;
						cout << "\t\t  ---------------" << endl;
						cout << "\t\t|0. Return      |" << endl;
						cout << "\t\t  ---------------" << endl;
						cout << "Enter your choices:" << endl;
						cin >> ch;
						switch (ch)
						{
						case 1:
							stu_add();
							break;
						case 2:
							stu_del();
							break;
						case 3:
							stu_mod();
							break;
						case 4:
							stu_find();
							break;
						case 5:
							stu_show();
							break;
						case 6:
							stu_sort();
							break;
						case 0:
							flag = 1;
							break;

						}
						if (flag)
						{
							break;//exit cycle
						}
					}
					system("cls");
					//
					break;
				case 2:
					//
					int as;

					while (true)
					{
						Account** Acc_M = new Account * [Acc_Num + 1];
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|1¡¢Add teacher account|" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|2. Deletion of teacher accounts|" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|3¡¢View all accounts|" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|4¡¢Change password    |" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "\t\t|0. Withdrawal        |" << endl;
						cout << "\t\t-----------------" << endl;
						cout << "Enter your choices:" << endl;
						cin >> ch;
						switch (ch)
						{
						case 1:
							while (true)
							{
								f = 0;

								cout << "Enter the teacher's employee number:" << endl;
								cin >> account;
								for (int iii = 0; iii < Stu_Num; iii++)
								{
									if (M_Account[iii]->account == account && M_Account[iii]->id == 2)
									{
										cout << "This teacher already exists, please re-enter..." << endl;
										f = 1;
										break;
									}
								}
								if (!f)
								{
									break;
								}
							}
							for (int xi = 0; xi < Acc_Num; xi++)
							{
								Acc_M[xi] = M_Account[xi];
							}
							Account* acc_m;
							acc_m = new Account(account, "111111", 2);
							Acc_M[Acc_Num] = acc_m;
							delete[]M_Account;
							M_Account = Acc_M;
							Acc_Num++;
							account_save();
							cout << "Added successfully..." << endl;
							system("pause");
							system("cls");
							break;
						case 2:
							cout << "Enter the teacher's employee number:" << endl;
							cin >> account;
							for (int ii = 0; ii < Acc_Num; ii++)
							{
								if (M_Account[ii]->account == account && M_Account[ii]->id == 2)
								{
									for (int jj = ii; jj < Acc_Num; jj++)
									{
										M_Account[jj] = M_Account[jj + 1];
									}
									break;
								}
							}
							Acc_Num--;
							account_save();
							cout << "Deleted successfully..." << endl;
							system("pause");
							system("cls");
							break;
						case 3:
							for (int i = 0; i < Acc_Num; i++)
							{
								M_Account[i]->display();
							}
							system("pause");
							system("cls");
							break;
						case 4:
							for (int ii = 0; ii < Acc_Num; ii++)
							{
								if (M_Account[ii]->account == ACCOUNT && M_Account[ii]->id == 3)
								{
									cout << "Enter the modified password:" << endl;
									cin >> password;
									M_Account[ii]->password = password;
									break;
								}
							}
							account_save();
							cout << "Successful modification..." << endl;
							system("pause");
							system("cls");
							break;
						case 0:
							flag = 1;
							break;
						}
						if (flag)
						{
							system("cls");
							break;
						}
					}
					system("cls");
					//
					break;
				case 0:
					system("cls");
					return;
					break;
				}
			}
			//
			return;

		}
		else
		{
			char  c;
			number--;
			cout << "That's three times. There's still time." << number << "second";
			cout << "Wrong password, do you want to re-enter it?. . .(y/n) " << endl;
			cin >> c;
			if (number == 0) {
				cout << "Wrong password for locking" << endl;
				cout << "Unable to re-enter password" << endl;
				_getch();
				system("cls");
				break;
			}
			//cout << "That's three times. There's still time." << number << "second";	
			system("pause");
			if (c == 'n')
			{
				system("cls");
				return;
			}
			system("cls");

		}
	}
}

void People_Manager::stu_sort()//Sorting students
{
	while (true)
	{
		system("cls");
		cout << "\t\t----------------" << endl;
		cout << "\t\t|1. Sequential ordering|" << endl;
		cout << "\t\t----------------" << endl;
		cout << "\t\t|2. Reverse order sorting|" << endl;
		cout << "\t\t----------------" << endl;
		cout << "\t\t|0. Return  |" << endl;
		cout << "\t\t----------------" << endl;
		cout << "Enter your choices:" << endl;
		int c;
		cin >> c;

		switch (c)
		{
		case 1:
			for (int i = 0; i < Stu_Num; i++)
			{
				for (int j = 0; j < Stu_Num - i - 1; j++)
				{
					if (M_Student[j]->num > M_Student[j + 1]->num)
					{
						swap(M_Student[j], M_Student[j + 1]);
					}
				}
			}
			cout << "Sort Success" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			for (int i = 0; i < Stu_Num; i++)
			{
				for (int j = 0; j < Stu_Num - i - 1; j++)
				{
					if (M_Student[j]->num < M_Student[j + 1]->num)
					{
						swap(M_Student[j], M_Student[j + 1]);
					}
				}
			}
			cout << "Sort Success" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			stu_save();
			return;
			break;
		}

	}

}

int People_Manager::acc_num()//Initialisation Quantity
{
	fstream f;
	f.open(FILENAME2, ios::in);
	int i = 0;
	int account;
	string password;
	int id;
	while (f >> account && f >> password && f >> id)
	{
		i++;
	}
	f.close();
	return i;
}

int People_Manager::pass_au(string& pass)//put up a censor while typing password
{
	char password[1024];
	int index = 0;
	while (1) {
		char ch;
		ch = _getch();
		if (ch == 8) {
			if (index > 0) {
				index--;
				cout << char(8) << " " << char(8);

			}
		}
		else
			if (ch == '\r') {
				password[index] = '\0';
				cout << endl;
				break;
			}
			else
			{
				cout << "*";
				password[index++] = ch;
			}
	}
	for (int i = 0; i < index; i++) {
		pass += password[i];
	}
}

/*The starts of the Registration domain*/

void Register::reg_WriteAcc()//"register - write account" write down all inputted user info inside a text file, will return to main menu after completion
{
	ofstream writefile;
	string file = username + ".txt";
	writefile.open(file.c_str());
	writefile << role << '\n';
	writefile << username << '\n';
	writefile << password << '\n';
	writefile.close();
	cout << "Your account has been created successfully!" << '\n';
	system("pause");
	system("cls");
}

void Register::reg_user()//"register user" obtain the inputted username, will pass on to 'reg_pass' after completion
{
	system("cls");
	cout << "\nPlease enter your new username: ";
	cin >> user_name;
	//line: 994 - 1005 will filter if the inputted username is identical any other usernames in the database
	ifstream username_check;
	username_temp = user_name + ".txt";
	cout << username_temp << '\n';
	username_check.open(username_temp.c_str());
	getline(username_check, username);
	getline(username_check, username);
	cout << username << '\n';
	if (user_name == username)
	{
		cout << "Username: " << user_name << " has been taken. Please enter a different username." << '\n';
		system("pause");
		reg_user();
	}
	username = user_name;
	cout << "\nUsername - \"" << username << "\"\nUsername cannot be rename after confirmation. Confirm? \n\n[1] Yes\n[2] No" << '\n';
	cin >> confirm;
	switch (confirm)
	{
	case '1'://continue for password making after user gives consent to the inputted username
		reg_pass();
		break;
	case '2'://in case user disagree with their name selection 
		cin.clear();
		cin.ignore(10000, '\n');
		reg_user();
		break;
	default:
		cout << "Invalid input. Please try again" << '\n';
		cin.clear();
		cin.ignore(10000, '\n');
		reg_user();
		break;
	}
}

void Register::reg_pass()//"register password" obtain the inputted password, will pass on to 'reg_WriteAcc' after completion 
{
	People_Manager censor;
	cout << "Please enter your new password:" << '\n';
	censor.pass_au(password);
	cout << "Please re-enter your new password:" << '\n';
	censor.pass_au(re_password);
	if (password == re_password)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		reg_WriteAcc();
	}
	else if (password != re_password)// if the new password and confirmation password do not match
	{
		cout << "Entered password is not the same!" << '\n';
		reg_pass();
	}
}

void Register::reg_role()//"register role" a role decider based on user input
{
	cout << "-------------------------" << '\n';
	cout << "     Role selection      " << '\n';
	cout << "-------------------------" << '\n';
	cout << "                         " << '\n';
	cout << "   [1] Student           " << '\n';
	cout << "                         " << '\n';
	cout << "   [2] Teacher           " << '\n';
	cout << "                         " << '\n';
	cout << "   [3] Staff             " << '\n';
	cout << "                         " << '\n';
	cout << "-------------------------" << '\n';
	cout << "Please enter your role: ";
	cin >> confirm;
	switch (confirm)
	{
	case '1':
		role = "student";//assign the student role to the newly created account
		reg_user();
		break;
	case '2':
		role = "teacher";//assign the teacher role
		reg_user();
		break;
	case '3':
		role = "admin";//assign the staff role
		reg_user();
		break;
	default:
		cout << "Invalid input. Please try again" << '\n';
		cin.clear();
		cin.ignore(10000, '\n');
		system("pause");
		system("cls");
		reg_role();
		break;
	}
}