#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private : 


    static void _ReadUpdateUserInfo(clsUser& User)
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
        cout << " -------------------------------------\n";

    }

     public:

         static void ShowUpdateUserScreen()
         {
             string Username = "";

             _DrawScreenHeader("\t Update User Screen");

             cout << "\nEnter Username : ";

             Username = clsInputValidate::ReadString();

             while (!clsUser::IsUserExist(Username))
             {
                 cout << "\nUsername is not Exist , Enter Another one : ";
                 Username = clsInputValidate::ReadString();
             }

             clsUser UpdateUser = clsUser::Find(Username);

             _PrintUserCard(UpdateUser);

             char answer = 'n';

             cout << "Do you want to update this user(y/n)? ";

             cin >> answer;

             if (answer == 'y' || answer == 'Y') 
             {
                 cout << "\n--------------------------------------\n";
                 cout << "\nUpdate Client Info : \n";
                 cout << "\n--------------------------------------\n";

                 _ReadUpdateUserInfo(UpdateUser);


                 clsUser::enSaveResults saveresult;

                 saveresult = UpdateUser.Save();

                 switch (saveresult)
                 {
                 case clsUser::enSaveResults::svSucceeded:

                     cout << "\nUser Updated Successfully :-)";
                     _PrintUserCard(UpdateUser);
                     break;

                 case clsUser::enSaveResults::svFaildEmptyObject:

                     cout << "\nError in Update User because it's Empty! \n";

                     break;

                 case clsUser::enSaveResults::svFaildAccountNumberExists:

                     cout << "\nError in Update User because Username is Used! \n";

                     break;
                 }
             }

             else 
             {
                 cout << "\nUser still not Updated : \n";

                 _PrintUserCard(UpdateUser);
             }
         }
};

