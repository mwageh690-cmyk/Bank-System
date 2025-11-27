#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsShowDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include <iomanip>

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private : 

	enum enManageUsersOptions{enListUsers = 1 , enAddNewUser = 2 , enDeleteUser = 3 , 
	
	 enUpdateUser = 4 , enFindUser = 5 , enMainMenue = 6};

	static short _ReadManageUsersOption() 
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToManageUsersScreen() 
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ShowListUsersScreen() 
	{
		/*cout << "\nList Users Screen will be here...\n";*/

		clsShowListUsersScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUserScreen() 
	{
		/*cout << "\nAdd New User Screen will be here...\n";*/

		clsAddNewUserScreen::ShowAddNewUserScreen();

	}

	static void _ShowDeleteUserScreen() 
	{
		/*cout << "\nDelete User Screen will be here...\n";*/

		clsShowDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() 
	{
		/*cout << "\nUpdate User Screen will be here....\n";*/

		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen() 
	{
		/*cout << "\nFind User Screen will be here....\n";*/

		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersOption(enManageUsersOptions option) 
	{
		switch (option) 
		{
		case enManageUsersOptions::enListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersScreen();

			break;
		}
		case enManageUsersOptions::enAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersScreen();

			break;
		}
		case enManageUsersOptions::enDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();

			break;
		}
		case enManageUsersOptions::enUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();

			break;
		}
		case enManageUsersOptions::enFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();

			break;
		}
		case enManageUsersOptions::enMainMenue:
		{


		}
		}
	}



public : 


	static void ShowManageUsersScreen() 
	{
		if (!CheakAccessRights(clsUser::enpermisions::emangeuser))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tManage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMaanage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());
	}
	

};