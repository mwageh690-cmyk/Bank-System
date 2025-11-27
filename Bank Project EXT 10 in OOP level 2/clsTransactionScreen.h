#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransfer.h"
#include "clsTransferLogScreen.h"
#include <iomanip>
using namespace std;


class clsTransactionScreen : protected clsScreen
{

private : 

	enum enTransActionMenue{enDeposit = 1 , enWithdraw = 2 , enTotalBalances = 3 , enTransfer = 4 ,enTransferLog = 5 ,enMainMenue = 6
	};

	static short _ReadTransactionMenue() 
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBacktoTransactionScreen() 
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
		ShowTransactionScreen();
	}

	static void _ShowDepositScreen() 
	{
		/*cout << "\nDeposit Screen Will be here...\n";*/

		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() 
	{
	/*	cout << "\nWithdraw Screen will be here....\n";*/

		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalances() 
	{
		/*cout << "\nTotal Balances will be here....\n";*/

		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		/*cout << "\nTransfer Screen will be here....\n";*/

		clsTransfer::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() 
	{
		/*cout << "\nTransfer Log Screen will be here...\n";*/

		clsTransferLogScreen::ShowTransferLogScreen();
	}


	static void _PerformTransactionMenueOption(enTransActionMenue enoption) 
	{
		switch (enoption) 
		{
		case enTransActionMenue::enDeposit:

		{
			system("cls");
			_ShowDepositScreen();
			_GoBacktoTransactionScreen();
			break;

		}
		case enTransActionMenue::enWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBacktoTransactionScreen();
			break;
		}
		case enTransActionMenue::enTotalBalances:
		{
			system("cls");
			_ShowTotalBalances();
			_GoBacktoTransactionScreen();
			break;
		}

		case enTransActionMenue ::enTransfer : 
		{
			system("cls");
			_ShowTransferScreen();
			_GoBacktoTransactionScreen();
			break;
		}

		case enTransActionMenue ::enTransferLog : 
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBacktoTransactionScreen();
			break;

		}
		case enTransActionMenue::enMainMenue:

		{
			

		}

		}
	}


public : 


	static void ShowTransactionScreen() 
	{
		if (!CheakAccessRights(clsUser::enpermisions::etransaction))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tTransaction Screen");


		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenueOption((enTransActionMenue)_ReadTransactionMenue());
	}

};