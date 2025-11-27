#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iomanip>
using namespace std;


class clsAddNewUserScreen : protected clsScreen
{

private : 


	static void _ReadNewUser(clsUser& User) 
	{
        cout << "\nEnter FirstName :  ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permision : ";

        User.Permisions = _ReadPermisiontoSet();


	}

    static int _ReadPermisiontoSet()
    {
        int permision = 0;
        char answer = 'n';

        cout << "do you want to give the user full access? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }
        cout << "\n\nDo you want to give access to this follows : \n";
        cout << "\ndo you want to show clints? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::eshowclint;
        }
        cout << "\nAdd new clint? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::eAddnewclint;
        }
        cout << "\nDelete clint? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::edeleteclint;
        }
        cout << "\nUpdate clint? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::eupdateclint;
        }
        cout << "\nFind clint? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::efindclint;
        }
        cout << "\nTransactions? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::etransaction;
        }
        cout << "\nMange Users? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::emangeuser;
        }

        cout << "\nLogin Register? (y/n)? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permision += clsUser::enpermisions::enloginRegister;
        }
        


        return permision;

    }

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
       
    }

  public : 

      static void ShowAddNewUserScreen() 
      {
          string Username = "";

          _DrawScreenHeader("\t Add New User Screen");

          cout << "\nEnter Username : ";

          Username = clsInputValidate::ReadString();

          while (clsUser::IsUserExist(Username)) 
          {
              cout << "\nUsername is Already Exist , Enter Another one : ";
              Username = clsInputValidate::ReadString();
          }

          clsUser User = clsUser::GetAddNewUserObject(Username);
          _ReadNewUser(User);

          clsUser::enSaveResults saveresult;

          saveresult = User.Save();

          switch (saveresult) 
          {
          case clsUser::enSaveResults::svSucceeded : 

              cout << "\nUser Added Successfully :-)";
              _PrintUserCard(User);
              break;

          case clsUser::enSaveResults::svFaildEmptyObject : 

              cout << "\nError in save User because it's Empty! \n";

              break;

          case clsUser ::enSaveResults::svFaildAccountNumberExists : 

              cout << "\nError in save User because Username is Used! \n";

              break;
          }
      }

       

};

