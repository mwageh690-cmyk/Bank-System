#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsTransfer : protected clsScreen
{
private : 
	static void _PrintClientCard(clsBankClient client)
	{
		cout << "\n------------------------------------";
		cout << "\nClient Card : \n";
		cout << " -------------------------------------\n";
        cout << "Full Name  : " << client.FullName() << endl;
		cout << "Acc.Number : " << client.AccountNumber() << endl;
	    cout << "Acc.Balance: " << client.AccountBalance << endl;
		cout << " -------------------------------------\n";

	}
	static string _ReadAccountNumber()
	{
		string s = "";

		cin >> s;

		while (!clsBankClient::IsClientExist(s)) 
		{
			cout << "\nAccount Number is Not Exist, enter another one ";
			cin >> s;
		}

		return s;
	}
	static double _ReadAmount(clsBankClient& client) 
	{
		double amount;

		cout << "\nEnter transfer amount? ";
		amount = clsInputValidate::ReadDblNumber();

		while (amount > client.AccountBalance) 
		{
			cout << "Amount Execeeds the avaliable balance , enter another one ";
			amount = clsInputValidate::ReadDblNumber();
		}
		return  amount;
	}

public : 


	static void ShowTransferScreen() 
	{
		_DrawScreenHeader("\t Transfer Screen");

		string AccountNumber1 = "";

		cout << "\nEnter Account Number to transfer from? ";

		AccountNumber1 = _ReadAccountNumber();

		clsBankClient SourceClient = clsBankClient::Find(AccountNumber1);
		_PrintClientCard(SourceClient);

		string AccountNumber2 = "";

		cout << "\nEnter Account Number to transfer to? ";
		AccountNumber2 = _ReadAccountNumber();

		while (AccountNumber2 == AccountNumber1) 
		{
			cout << "\nYou Cannot transfer to same account number, enter another one : ";
			AccountNumber2 = _ReadAccountNumber();
		}

		clsBankClient DestianceClient = clsBankClient::Find(AccountNumber2);

	   _PrintClientCard(DestianceClient);


		double amount = _ReadAmount(SourceClient);

		char answer = 'n';
		cout << "\nAre you sure to perform this operation (y/n)? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (SourceClient.Transfer(amount, DestianceClient)) 
			{
				cout << "\nTransfer Done Successfully :-)\n";
			}
			else 
			{
				cout << "\nTransfer Failed :-(\n";
			}
		}

		else 
		{
			cout << "\nTransfer operation isn't done :-(\n";
		}
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestianceClient);



	}


};

