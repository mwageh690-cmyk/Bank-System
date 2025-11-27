#pragma once
#include <iostream>
#include <string>
using namespace std;

class InterfaceCommnucation
{
public : 

	virtual void SendEmail(string Text, string Body) = 0;
	virtual void SendSMS(string Text, string Body) = 0;
	virtual void SendFax(string Text, string Body) = 0;

};

