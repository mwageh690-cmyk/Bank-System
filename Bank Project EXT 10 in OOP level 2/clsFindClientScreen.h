#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

	

	static void ShowFindClientScreen() 
	{
		if (!CheakAccessRights(clsUser::enpermisions::efindclint))
		{
			return;
		}
		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number? ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe Account Number is not Found , Enter Another one : ";

			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient SearchClient = clsBankClient::Find(AccountNumber);

		if (!SearchClient.IsEmpty())
		{
			cout << "\nClient Found :-)";
			_PrintClientCard(SearchClient);
		}

		else
		{
			cout << "\nClient is not Found :-(";
		}
		

	}

};