#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;


class clsFindUserScreen : protected clsScreen
{

private : 

    static void _PrintUserCard(clsUser User)
    {
        cout << "\n------------------------------------";
        cout << "\nUser Card : \n";
        cout << " -------------------------------------\n";
        cout << "First Name : " << User.FirstName << endl;
        cout << "Last Name  : " << User.LastName << endl;
        cout << "Full Name  : " << User.FullName() << endl;
        cout << "Email      : " << User.Email << endl;
        cout << "Phone      : " << User.Phone << endl;
        cout << "Password   : " << User.Password << endl;
        cout << "Permisions : " << User.Permisions << endl;
        cout << " -------------------------------------\n";

    }

public : 

    static void ShowFindUserScreen() 
    {
        string Username = "";

        _DrawScreenHeader("\t Find User Screen");

        cout << "\nEnter Username : ";

        Username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not Exist , Enter Another one : ";
            Username = clsInputValidate::ReadString();
        }

        clsUser FindUser = clsUser::Find(Username);

        if (!FindUser.IsEmpty()) 
        {
            cout << "User is Found :-)\n";
            _PrintUserCard(FindUser);
        }

        else 
        {
            cout << "Error in User  Found because it's Empty \n";
            _PrintUserCard(FindUser);
        }

    }

};

