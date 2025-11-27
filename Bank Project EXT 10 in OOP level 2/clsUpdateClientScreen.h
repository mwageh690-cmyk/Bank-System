#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h";
#include "clsScreen.h"

using namespace std;


class clsUpdateClientScreen : protected clsScreen
{

private : 

	static void _ReadClientInfo(clsBankClient& client) 
	{
		cout << "\nEnter First Name : ";
		client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name : ";
		client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Pincode : ";
		client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Balance : ";
		client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

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

	static void ShowUpdateClientScreen() 
	{
		if (!CheakAccessRights(clsUser::enpermisions::eupdateclint))
		{
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen");
		string AccountNumber = "";

		cout << "\nPlease Enter Account Number? ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe Account Number is not Found , Enter Another one : ";

			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient UpdateClient = clsBankClient::Find(AccountNumber);

		_PrintClientCard(UpdateClient);

		char Answer = 'n';

		cout << "\nAre you sure Update This Client (y/n) ? ";
		cin >> Answer;

		

		if (Answer == 'y' || Answer == 'Y') 
		{
			cout << "\n--------------------------------------\n";
			cout << "\nUpdate Client Info : \n";
			cout << "\n--------------------------------------";
			
           _ReadClientInfo(UpdateClient);

		   clsBankClient::enSaveResults saveresult;

		   saveresult = UpdateClient.Save();

		   switch (saveresult)
		   {
		   case clsBankClient::enSaveResults::svSucceeded :

			   cout << "\nAccount Updated Successfully :-)";
			   _PrintClientCard(UpdateClient);
			   break;

		   case clsBankClient::enSaveResults::svFaildEmptyObject : 

			   cout << "\nAccount is not Saved because it's Empty! ";
			   break;
		   case clsBankClient ::enSaveResults::svFaildAccountNumberExists : 

			   cout << "\nAccount is not Saved because Account Number Is Already Exist! ";
			   break;
		   }

		}
		else 
		{
			cout << "\nAccount Still Not Updated! ";
			_PrintClientCard(UpdateClient);
		}
	}
};

