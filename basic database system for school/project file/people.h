#include"account.h"

class People_Manager
{
public:

	int Stu_Num;//Number of students
	Student** M_Student;//Student array pointer

	void stu_init();//Initialize
	int stu_num();//Initial quantity

	int Acc_Num;//Account number
	Account** M_Account;//Account array pointer

	void acc_init();//Initialize
	int acc_num();//Initial quantity


	void account_save();//Account preservation
	void stu_add();//Add a student
	void stu_sort();//Sort student
	void stu_del();//Delete a student
	void stu_mod();//Modifying student
	void stu_find();//Find a student
	void stu_save();//Preserve students
	void stu_show();//Display student
	void stu_oper();//Student operation
	void tea_oper();//Teacher operation
	void man_oper();//Admin operation
	int pass_au(string&);//Password censoring system 
};

class Register
{
public:

	char confirm;
	char choice;
	string username, user_name, password, re_password, file_name, role, username_temp;

	void reg_WriteAcc();
	void reg_user();
	void reg_pass();
	void reg_role();
};