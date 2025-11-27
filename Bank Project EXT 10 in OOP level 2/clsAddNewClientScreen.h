#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& client)
	{
		cout << "\nEnter First Name ? ";
		client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name ? ";
		client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email ? ";
		client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone ? ";
		client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Pincode ? ";
		client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance ? ";
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

public:


	static void ShowAddNewClientScreen()
	{
		if (!CheakAccessRights(clsUser::enpermisions::eAddnewclint))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");

		string Accountnumber = "";

		cout << "\nPlease Enter Account Number: ";
		Accountnumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(Accountnumber))
		{
			cout << "\nAccount Number Is Already Used , Enter Anthor one :  ";
			Accountnumber = clsInputValidate::ReadString();
		}

		clsBankClient newclient = clsBankClient::GetAddNewClientObject(Accountnumber);

		_ReadClientInfo(newclient);

		clsBankClient::enSaveResults saveresult;

		saveresult = newclient.Save();

		switch (saveresult)
		{
		case clsBankClient::enSaveResults::svSucceeded:

			cout << "\nClient Added Successfully :-) ";

			_PrintClientCard(newclient);

			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:

			cout << "\nThe Client Doesn't Save Beacasue it's Empty! \n";

			break;

		case clsBankClient::enSaveResults::svFaildAccountNumberExists:

			cout << "\nThe Client Dosen't save Beacuse The Account Number Is Already Exist! \n";
			break;
		}


	}


};