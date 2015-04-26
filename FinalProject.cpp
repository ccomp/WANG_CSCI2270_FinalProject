#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "poker.h"

using namespace std;

/*
Function Prototype:
	int main()
Function Description:
	This is the main function that runs everything
Example:
	int main()
Pre Condition:
	All functions within the main function executes properly
Post Condition:
	Code Runs
*/

int main()
{
	string userName;
	poker* OBJ = new poker();
	string command = "jfkdsakdjdflsdafjdlsak";
	int menuCommand = 0;
	OBJ->displayTitle();
	cout<<"command: ";
	cin>>command;
	while(command != "f")
	{	
		cout<<"command: ";
		cin>>command;
	}
	cout<<"Enter a User Name: ";
	cin>>userName;
	OBJ->setUserName(userName);
	cout<<endl;
	while(menuCommand != 5)
	{
		//OBJ->displayValues();
		cout<<endl;
		OBJ->displayMenu();	
		cout<<"Please Enter a Command:"<<endl;
		cout<<"Command: ";
		cin>>menuCommand;
		if(menuCommand != 5)
		{
			cout<<endl;
			if(menuCommand == 1)
			{
				OBJ->setMoney(-1);
				OBJ->setPlayerCards();
				OBJ->displayValues();
				cout<<endl;
			    OBJ->displayTable();
				OBJ->hold();
			}
			if(menuCommand == 2)
			{
				OBJ->setMoney(-2);
				OBJ->setPlayerCards();
				OBJ->displayValues();
				cout<<endl;
			    OBJ->displayTable();
				OBJ->hold();
			}
			if(menuCommand == 3)
			{
				OBJ->setMoney(-3);
				OBJ->setPlayerCards();
				OBJ->displayValues();
				cout<<endl;
			    OBJ->displayTable();
				OBJ->hold();
			}

			if(menuCommand == 1 || menuCommand == 2 || menuCommand == 3)
			{
				OBJ->sortRiver();
				//OBJ->testRiver();
				OBJ->displayValues();
				OBJ->handChecker(menuCommand);
				
				cout<<endl;
				OBJ->displayTable();
				cout<<endl;
				cout<<"--------------------------------New Round-------------------------------"<<endl;
				cout<<endl;
			}
			if(menuCommand == 4)
			{
				OBJ->displayRules();
			}
		}
		OBJ->resetDeck();


	}
	/*

	cout<<"Do you want to save your progress? (1 = yes, 2 = no)"<<endl;
	cout<<"Command: ";
	cin>>menuCommand;
	if(menuCommand == 1)
	{

	}
	*/


	cout<<"Thanks for Playing!"<<endl;
	
	//OBJ->assignCards()->suit;

	return 0;
}
