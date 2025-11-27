#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsTransferLogScreen : protected clsScreen
{

private : 

	static void _PrintLogRegisterLine(clsBankClient::sttransferlog TransferLog) 
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << TransferLog.DateAndTime;
		cout << "| " << setw(10) << left << TransferLog.SourceAccountNumber;
		cout << "| " << setw(10) << left << TransferLog.DestionationAccountNumber;
		cout << "| " << setw(10) << left << TransferLog.Amount;
		cout << "| " << setw(10) << left << TransferLog.SourceBalance;
		cout << "| " << setw(10) << left << TransferLog.destionationBalace;
		cout << "| " << setw(10) << left << TransferLog.User;

	}


public : 

	static void ShowTransferLogScreen() 
	{
		vector <clsBankClient::sttransferlog> vtransferlog = clsBankClient::GetTransferLogList();

		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vtransferlog.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vtransferlog.size() == 0)
			cout << "\t\t\t\tNo Transfer done In the System!";
		else

			for (clsBankClient::sttransferlog &Transfer : vtransferlog)
			{

				_PrintLogRegisterLine(Transfer);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

