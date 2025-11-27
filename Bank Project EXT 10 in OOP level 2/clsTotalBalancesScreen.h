#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>
class clsTotalBalancesScreen : protected clsScreen
{

private:
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;


    }

public : 

    static void ShowTotalBalancesScreen() 
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        double totalbalnces = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";

        else 

            for (clsBankClient Client : vClients) 
            {
                PrintClientRecordLine(Client);
                cout << endl;

            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t Total Balances is : " << totalbalnces << endl;
        cout << setw(8) << left << "" << "\t\t ( " << clsUtil::NumberToText(totalbalnces) << " ) ";


    }

};