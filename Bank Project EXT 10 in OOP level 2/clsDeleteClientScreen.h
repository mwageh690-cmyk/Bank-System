#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;


class clsDeleteClientScreen : protected clsScreen
{

private : 

	static void _PrintClientCard(clsBankClient client)
	{
		cout << "\n------------------------------------";
		cout << "\nClient Card : \n";
		cout << " -------------------------------------\n";

		cout << "First Name : " << client.FirstName << endl;
		cout << "Last Name  : " << client.LastName << endl;
		cout << "Full Name  : " << client.FullName() << endl;
		cout << "Email      : " << client.Email << endl;
		cout << "Phone      : " << client.Phone << endl;
		cout << "Acc.Number : " << client.AccountNumber() << endl;
		cout << "Password   : " << client.PinCode << endl;
		cout << "Acc.Balance: " << client.AccountBalance << endl;

	}

public : 

	static void ShowDeleteClientScreen() 
	{
		if (!CheakAccessRights(clsUser::enpermisions::edeleteclint))
		{
			return;
		}
		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number? ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) 
		{
			cout << "\nThe Account Number is not Found , Enter Another one : ";

			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);

		_PrintClientCard(DeleteClient);

		char answer = 'n';

		cout << "\nAre you sure you want delete this client (y/n) ? ";

		cin >> answer;

		if (answer == 'y' || answer == 'Y') 
		{
			if (DeleteClient.Delete()) 
			{
				cout << "\nClient Deleted Successfully :-)";
				_PrintClientCard(DeleteClient);
			}
			else 
			{
				cout << "\nClient is not delete because it's Empty.";
			}
		}

		else 
		{
			cout << "\nClient is not delete.";
		}

	}

};