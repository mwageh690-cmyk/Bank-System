#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string s = "";

		cin >> s;

		return s;
	}


public : 


	static void ShowWithdrawScreen() 
	{
		_DrawScreenHeader("\t Withdraw Screen");

		cout << "\nEnter Account Number? ";

		string accountnumber = "";

		accountnumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(accountnumber))
		{
			cout << "\nClient with [" << accountnumber << "] does not exist.";
			cout << "\nEnter Account Number? ";
			accountnumber = _ReadAccountNumber();

		}

		clsBankClient client1 = clsBankClient::Find(accountnumber);

		_PrintClientCard(client1);

		cout << "\nPlease enter withdraw amount? ";

		double amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction? ";
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y') 
		{
			if (client1.Withdraw(amount)) 
			{
				
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is : " << client1.AccountBalance;
			}

			else 
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to Withdraw is : " << amount;
				cout << "\nYour Balance is : " << client1.AccountBalance;
			}
		}

		else 
		{
			cout << "\nOperation was Cancelled.\n";
		}

	}


};

