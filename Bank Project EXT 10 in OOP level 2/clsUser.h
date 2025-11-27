#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>
using namespace std;


class clsUser : public clsPerson
{
private : 

	enum enmode{enemptymode = 0 , enUpdatemode = 1 , enaddnew = 2};

	enmode _mode;
    string _UserName;
	string _Password;
	int _Permisions;
    bool _MarkForDelete = false;

	struct stloginregister;
	static stloginregister _ConvertLoginRegisterLineToRecord(string line, string sperator = "#//#") 
	{
		stloginregister LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(line, sperator);

		LoginRegisterRecord.dateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.username = LoginRegisterDataLine[1];
		LoginRegisterRecord.password = LoginRegisterDataLine[2];
		LoginRegisterRecord.permission = stoi(LoginRegisterDataLine[3]);

		return  LoginRegisterRecord;

	}

	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsUser(enmode::enUpdatemode , vClientData[0] , vClientData[1] , vClientData[2] , vClientData[3] , 
			vClientData[4] , vClientData[5] , stoi(vClientData[6]));

	}

	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord += User.Password  + Seperator;
		stUserRecord += to_string(User.Permisions);

		return stUserRecord;

	}

	static string _covertuserinloginregisterline(clsUser &user, string dlem = "#//#") 
	{
		string line = "";

		line += clsDate::DateToString(clsDate()) + "-" + clsDate::GetTimeNow(":") + dlem;
		line += user.UserName + dlem;
		line += user.Password + dlem;
		line += to_string(user.Permisions);

		return line;
	}

	static  vector <clsUser> _LoadUsersDataFromFile()
	{

		vector <clsUser> vClients;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLinetoUserObject(Line);

				vClients.push_back(User);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vClients)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsUser> _vClients;
		_vClients = _LoadUsersDataFromFile();

		for (clsUser& C : _vClients)
		{
			if (C.UserName == UserName)
			{
				C = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vClients);

	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enmode::enemptymode, "", "", "", "", "", "", 0 );
	}




public : 

	enum enpermisions { eALL = -1, eshowclint = 1, eAddnewclint = 2, edeleteclint = 4
		, eupdateclint = 8, efindclint = 16, etransaction = 32, emangeuser = 64 , enloginRegister = 128 };

	struct stloginregister 
	{
		string dateTime;
		string username;
		string password;
		int permission;
	};




	clsUser(enmode mode, string firstname, string lastname, string email,
		string phone, string username, string password, int permisions)
		: clsPerson(firstname, lastname, email, phone)
	{
		_mode = mode;
		_UserName = username;
		_Password = password;
		_Permisions = permisions;
	}

	bool IsEmpty()
	{
		return (_mode == enmode::enemptymode);
	}

	bool MarkedForDeleted()
	{
		return  _MarkForDelete;
	}

	void SetUsername(string username) 
	{
		_UserName = username;
	}
    string GetUserName() 
	{
		return _UserName;
	}
   __declspec(property(get = GetUserName, put = SetUsername)) string UserName;


   void SetPassword(string password)
   {
	   _Password = password;
   }
   string GetPassword()
   {
	   return   _Password;
   }
   __declspec(property(get = GetPassword, put = SetPassword)) string Password;


   void SetPermision(int permisions)
   {
	   _Permisions = permisions;
   }
   int GetPermisions() 
   {
	   return  _Permisions;
   }
  __declspec(property(get = GetPermisions, put = SetPermision)) int Permisions;

   void Print()
   {
		 cout << "\nUser Card:";
		 cout << "\n___________________";
		 cout << "\nFirstName   : " << FirstName;
		 cout << "\nLastName    : " << LastName;
		 cout << "\nFull Name   : " << FullName();
		 cout << "\nEmail       : " << Email;
		 cout << "\nPhone       : " << Phone;
		 cout << "\nUser Name   : " << _UserName;
		 cout << "\nPassword    : " << _Password;
		 cout << "\nPermisions  : " << _Permisions;
		 cout << "\n___________________\n";

   }


  static clsUser Find(string Username)
  {


	  fstream MyFile;
	  MyFile.open("Users.txt", ios::in);//read Mode

	  if (MyFile.is_open())
	  {
		  string Line;
		  while (getline(MyFile, Line))
		  {
			  clsUser Client = _ConvertLinetoUserObject(Line);
			  if (Client.UserName == Username)
			  {
				  MyFile.close();
				  return Client;
			  }

		  }

		  MyFile.close();

	  }

	  return _GetEmptyUserObject();
  }

  static clsUser Find(string Username, string Password)
  {



	  fstream MyFile;
	  MyFile.open("Users.txt", ios::in);//read Mode

	  if (MyFile.is_open())
	  {
		  string Line;
		  while (getline(MyFile, Line))
		  {
			  clsUser Client = _ConvertLinetoUserObject(Line);
			  if (Client.UserName == Username && Client.Password  == Password)
			  {
				  MyFile.close();
				  return Client;
			  }

		  }

		  MyFile.close();

	  }
	  return _GetEmptyUserObject();
  }

  enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
  enSaveResults Save()
  {

	  switch (_mode)
	  {
	  case enmode::enemptymode:
	  {
		  if (IsEmpty())
		  {

			  return enSaveResults::svFaildEmptyObject;

		  }

	  }

	  case enmode::enUpdatemode:
	  {


		  _Update();

		  return enSaveResults::svSucceeded;

		  break;
	  }

	  case enmode::enaddnew:
	  {
		  //This will add new record to file or database
		  if (clsUser::IsUserExist(_UserName))
		  {
			  return enSaveResults::svFaildAccountNumberExists;
		  }
		  else
		  {
			  _AddNew();

			  //We need to set the mode to update after add new
			  _mode = enmode::enUpdatemode;
			  return enSaveResults::svSucceeded;
		  }

		  break;
	  }
	  }



  }

  static bool IsUserExist(string Username)
  {

	  clsUser User = clsUser::Find(Username);
	  return (!User.IsEmpty());
  }

  bool Delete()
  {
	  vector <clsUser> _vClients;
	  _vClients = _LoadUsersDataFromFile();

	  for (clsUser& C : _vClients)
	  {
		  if (C.UserName == _UserName)
		  {
			  C._MarkForDelete = true;
			  break;
		  }

	  }

	  _SaveUsersDataToFile(_vClients);

	  *this = _GetEmptyUserObject();

	  return true;

  }

  static clsUser GetAddNewUserObject(string Username)
  {
	  return clsUser(enmode::enaddnew, "", "", "", "", Username, "", 0);
  }

  static vector <clsUser> GetUsersList()
  {
	  return _LoadUsersDataFromFile();
  }

  bool CheakAccessPermission(enpermisions permission) 
  {
	  if (_Permisions == enpermisions::eALL)
		  return true;
	  if ((permission & _Permisions) == permission)

		  return true;
	  else
		  return false;
  }

   void AddloginstoRegisterFile()
   {
	  fstream file;

	  file.open("LoginRegister", ios::out | ios::app);

	  string line = "";
	 

       if (file.is_open()) 
	   {
		   line = _covertuserinloginregisterline(*this);
		  file << line << endl;

		  file.close();
	   }
   }


   static vector<stloginregister> GetloginRegisterlist()
   {
	   vector <stloginregister> vLoginRegisterRecord;

	   fstream file;

	   file.open("LoginRegister", ios::in);

	   if (file.is_open()) 
	   {
		   string line;
		   stloginregister LoginRegisterRecord;

		   while (getline(file, line)) 
		   {
			   LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
			   vLoginRegisterRecord.push_back(LoginRegisterRecord);
		   }
		   file.close();

	   }

	   return  vLoginRegisterRecord;
   }


  

};


