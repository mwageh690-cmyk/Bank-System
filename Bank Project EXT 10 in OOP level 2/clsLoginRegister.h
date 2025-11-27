#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include <iomanip>
using namespace std;


class clsLoginRegister : protected clsScreen
{

private : 

	static void _PrintLoginRegisterRecordLine(clsUser::stloginregister LoginRegister) 
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegister.dateTime;
		cout << "| " << setw(20) << left << LoginRegister.username;
		cout << "| " << setw(20) << left << LoginRegister.password;
		cout << "| " << setw(10) << left << LoginRegister.permission;

	}

public : 

	static void ShowLoginRegisterScreen() 
    {
		if (!CheakAccessRights(clsUser::enpermisions::enloginRegister))
		{
			return;
		}
		vector <clsUser::stloginregister> vUsers = clsUser::GetloginRegisterlist();
		string Title = "\t  Loin Register  List Screen";
		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stloginregister User : vUsers)
			{

				_PrintLoginRegisterRecordLine(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}

};

