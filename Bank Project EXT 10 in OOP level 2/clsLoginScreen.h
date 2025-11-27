#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

using namespace std;


class clsLoginScreen : protected clsScreen
{
private : 

	static bool _Login() 
	{
		bool LoginFailed = false;
		short counter = 3;

		string Username, Password;

		do 
		{

			if (LoginFailed) 
			{
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " << counter << " Trials to login.\n\n";
			}

			if (counter == 0) 
			{
				cout << "\nYou are Locked after 3 failed trials.\n";
				return false;
			}
			//if statment for blocking the user

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

			counter = counter - 1;

			
		} while (LoginFailed);

		CurrentUser.AddloginstoRegisterFile();

		clsMainScreen::ShowMainMenue();

		return true;
		
	}


public : 

	static bool ShowLoginScreen() 
	{
		system("cls");

		_DrawScreenHeader("\t Login Screen");

		return _Login();

	}

};

