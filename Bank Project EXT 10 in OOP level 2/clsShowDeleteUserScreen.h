#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsShowDeleteUserScreen : protected clsScreen
{
private:

	static void _PrintUserCard(clsUser User)
	{
		cout << "\n------------------------------------";
		cout << "\nUser Card : \n";
		cout << " -------------------------------------\n";

		cout << "First Name : " << User.FirstName << endl;
		cout << "Last Name  : " << User.LastName << endl;
		cout << "Full Name  : " << User.FullName() << endl;
		cout << "Email      : " << User.Email << endl;
		cout << "Phone      : " << User.Phone << endl;
		cout << "Username   : " << User.UserName << endl;
		cout << "Password   : " << User.Password << endl;
		cout << "Permisions : " << User.Permisions << endl;
		cout << " -------------------------------------\n";

	}


public : 

	static void ShowDeleteUserScreen() 
	{
		_DrawScreenHeader("\t Delete User Screen");

		string Username = "";

		cout << "\nPlease Enter Account Number? ";

		Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nThe User is not Found , Enter Another one : ";

			Username = clsInputValidate::ReadString();

		}

		clsUser DeleteUser = clsUser::Find(Username);

		_PrintUserCard(DeleteUser);

		char answer = 'n';

		cout << "\nAre you sure you want delete this user (y/n) ? ";

		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (DeleteUser.Delete())
			{
				cout << "\nUser Deleted Successfully :-)";

				_PrintUserCard(DeleteUser);
			}
			else
			{
				cout << "\nUser is not delete because it's Empty.";
			}
		}

		else
		{
			cout << "\nUser is not delete.";
		}

	}

};