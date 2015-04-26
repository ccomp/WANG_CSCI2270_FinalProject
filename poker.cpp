	/*
List of Suits for reference
1. Highest Card
2. 1 Pair
3. 2 Pair
4. 3 of a Kind
5. 4 of a Kind
6. Full House
7. Straight
8. Flush
9. Straight Flush
*/


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "poker.h"

using namespace std;
/*
Prototype: 
	void poker::displayTitle();
Description: 
	Displays the title screen 
Example: 
	poker OBJ;
	OBJ->displayTitle()
Pre Condition: No preconditions necessary
Post Condition: After this function executes you will now see the title displayed

*/
void poker::displayTitle(){
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"| ------------------------------------------------------------------------- |"<<endl;
	cout<<"||       #####          #####        #    #    ########     #####          ||"<<endl;
	cout<<"||FLASH  #    ##      ###   ###      #   #     #            #    ##        ||"<<endl;
	cout<<"||       #      #    ##       ##     #  #      #            #      #       ||"<<endl;
	cout<<"||       #      #    #         #     # #       #            #      #       ||"<<endl;
	cout<<"||       #    ##     #         #     ##        ######       #    ##        ||"<<endl;
	cout<<"||       #####       #         #     # #       #            #####          ||"<<endl;
	cout<<"||       #           #         #     #  #      #            # ##           ||"<<endl;
	cout<<"||       #           ##       ##     #   #     #            #  ##          ||"<<endl;
	cout<<"||       #            ###   ###      #    #    #            #   ##         ||"<<endl;
	cout<<"||       #              #####        #     #   ########     #    ##        ||"<<endl;
	cout<<"|---------------------------------------------------------------------------|"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"                         @@@@@@@@@@@@@@@@@@@@@@@@@@@                         "<<endl;
    cout<<"                        @@                          @@                       "<<endl;
    cout<<"                       @@  Press f & Enter to Start  @@                      "<<endl;
	cout<<"                        @@                          @@                       "<<endl;
	cout<<"                         @@@@@@@@@@@@@@@@@@@@@@@@@@@                         "<<endl;
}

/*
Function Protoype: 
	card* poker::assignCards()
	
Description: 
	This method assigns a card to any slot through random number generation and putsused cards into a vector
	
Example:
	poker OBJ;
	OBJ->assignCards()

Precondition: None
Post Condition: Random card is picked and stored

*/
card* poker::assignCards()
{
	srand(time(NULL));
	int randomNumber = rand() % num;
	while(find(stupidSolution.begin(),stupidSolution.end(), randomNumber) != stupidSolution.end())
	{
		randomNumber = rand() % num;
		//cout<<randomNumber<<", ";
	}
	stupidSolution.push_back(randomNumber);
	//cout<<"->>";
	


	card* c = new card;
	c->weight = weightArr[randomNumber];
	c->suit = suitArr[randomNumber];

	//num--;
	return c;
}

/*
Function prototype:
	void poker::resetDeck()
Function Description:
	This method resets the deck after one round 
Example:
	poker OBJ;
	OBJ->resetDeck()
Pre Condition: 
	None
Post Condition: 
	Clears the vector and resets the cards


*/

void poker::resetDeck()
{

	stupidSolution.clear();

}

void poker::setPlayerCards()
{
	for(int i = 0; i < 5; i++)
	{
		riverArr[i] = assignCards();
	}

}

/*
Function Prototype:
	void poker::displayTable()
FUnction Description:
	This method displays all the cards on the table and with the shuffled cards
Example:
	poker OBJ;
	OBJ->displayTable()
Pre Condition: 
	riverArr is not empty
Post Condition:
	Display of cards is printed on screen

*/

void poker::displayTable()
{
	/*
	card* c1 = new card(assignCards());
	card* c2 = new card(assignCards());
	*/
	cout<<endl;
	river = 5;

	for(int i = 0; i < river; i++)
	{
		cout<<"#########   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		cout<<"#       #   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		string p = "";
		if(riverArr[i]->weight == "1")
			p = "A";
		else if(riverArr[i]->weight == "11")
			p = "J";
		else if(riverArr[i]->weight == "12")
			p = "Q";
		else if(riverArr[i]->weight == "13")
			p = "K";
		else
			p = riverArr[i]->weight;
		if(riverArr[i]->weight != "10")
		{
			cout<<"#   "<<p<<"   #   ";
		}
		else
		cout<<"#   "<<p<<"  #   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		cout<<"#       #   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		cout<<"#   "<<riverArr[i]->suit<<"   #   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		cout<<"#       #   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		cout<<"#########   ";
	}
	cout<<endl;
	for(int i = 0; i < river; i++)
	{
		cout<<"    "<<i+1<<"       ";
	}
	cout<<endl;
	cout<<"Money: "<<money<<endl;
	cout<<endl;
	
		
}

/*
Function Prototype:
	void poker::hold()
Function Description:
	Asks for which cards the user wants to discard
Example:
	poker OBJ;
	OBJ->hold()
Pre Condition: 
	riverArr is not empty, 
Post Condition:
	Assigns cards to be discarded
*/

void poker::hold()
{
	int cardsToHold = 0;
	cout<<"Which cards do you want to discard?    *Hit '6' when done!"<<endl;
	cout<<"Cards: ";

	cin >> cardsToHold;

	while(cardsToHold != 6)
	{
		riverArr[cardsToHold-1] = assignCards();
		cout<<"Which card do you want to discard?    *Hit '6' when done!"<<endl;
		cout<<"Card: ";

		cin >> cardsToHold;
	}
	

}

/*
Function Protoype:
	void poker::sortRiver()
Function Description:
	Bubble sorts the cards on screen 
Example:
	poker OBJ;
	OBJ->sortRiver()
Pre Condition:
	riverArr is not empty, 
Post Condition:
	Cards are sorted and can now be checked for hands

*/

void poker::sortRiver()
{
	for (int i = 0; i < 5; i ++)
	{
		totalArr[i] = riverArr[i];
	}
	card* swap;
	int n = 5;
    for(int c = 0; c < n - 1; c++)
    {
        for(int d = 0; d < n - c - 1; d++)
        {
            if(stoi(totalArr[d]->weight) > stoi(totalArr[d+1]->weight))
            {
                swap = totalArr[d];
                totalArr[d] = totalArr[d+1];
                totalArr[d+1] = swap;
            }
        }
    }
}

/*
Function Prototype:
	bool poker::isStraight()
Function Description:
	This method checks the cards for a straight
Example:
	poker OBJ;
	OBJ->isStraight()
Pre Condition:
	riverArr is not empty and sortRiver() has run
Post Condition:
	Returns true if straight is found
*/

bool poker::isStraight()
{
	int count = 0;
	for(int i = 0; i < 4; i++)
	{
		if(stoi(totalArr[i]->weight)+1 == stoi(totalArr[i+1]->weight))
		{
			count++;
		}
	}
	if(totalArr[0]->weight == "1" && totalArr[1]->weight == "10" && totalArr[2]->weight == "11" && totalArr[3]->weight == "12" && totalArr[4]->weight == "13")
	{
		count = 4;
	}
	if(count == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isFlush()
Function Description:
	This method checks if there is a Flush in the hand
Example:
	poker OBJ;
	OBJ->isFlush()
Pre Condition:
	riverArr is not empty and sortRiver() has run;
Post Condition:
	Returns True if hand contains a flush
*/

bool poker::isFlush()
{
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	
	for (int i = 0; i < 5; i++)
	{
		if(totalArr[i]->suit == "♥")
		{
			count1++;
		}
		if(totalArr[i]->suit == "♦")
		{
			count2++;
		}
		if(totalArr[i]->suit == "♣")
		{
			count3++;
		}
		if(totalArr[i]->suit == "♠")
		{
			count4++;
		}
	}
	if(count1 == 5 || count2 == 5 || count3 == 5 || count4 == 5)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*
Function Prototype:
	boolPoker::isFourOfAKind()
Function Description:
	This method checks the hand for Four of a kind
Example:
	poker OBJ;
	OBJ->isFOurOFAKind()
Pre Condition:
	riverArr and totalArr are not empty and sortRiver() has run
Post Condition:
	Returns true if Four of a kind is found
*/

bool poker::isFourOfAKind()
{
	/*
	int count = 0;
	for(int i = 0; i < 2;i++)
	{
		for(int m = 1; m < 4; m++)
		{
			if(totalArr[i]->weight == totalArr[i+m]->weight)
			{
				count++;
				
			}
			
		}
	}
	if(count == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/

	if((totalArr[0]->weight == totalArr[1]->weight && totalArr[0]->weight == totalArr[2]->weight && totalArr[0]->weight == totalArr[3]->weight) || (totalArr[1]->weight == totalArr[2]->weight && totalArr[1]->weight == totalArr[3]->weight && totalArr[1]->weight == totalArr[4]->weight))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isRoyalFlush()
Function Description:
	This method checks the hand for a Royal Flush
Example:
	poker OBJ;
	OBJ->isRoyalFlush()
Pre Condition:
	riverArr and totalArr is not empty and sortRiver() has run
Post Condition:
	Returns ture if Royal FLush is found
*/

bool poker::isRoyalFlush()
{
	bool flag1 = isFlush();
	bool flag2 = isStraight();
	card* lastCard = totalArr[4];
	card* firstCard = totalArr[0];
	if(flag1 == true && flag2 == true && lastCard->weight == "13" && firstCard->weight == "1")
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isStraightFlush()
Function Description:
	This method searches the hand for a Straight Flush
Example:
	poker OBJ;
	OBJ->isStraightFlush
Pre Condition:
	isFlush() isStraight() isRoyalFlush() and sortRiver() has run
Post Condition:
	Returns ture if Straight Flush is found
*/

bool poker::isStraightFlush()
{
	bool flag1 = isFlush();
	bool flag2 = isStraight();
	bool flag3 = isRoyalFlush();
	if(flag1 == true && flag2 == true && flag3 == false)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isThreeofAKind()
Function Description
	This method searches for a Three of a Kind
Example:
	poker OBJ;
	OBJ->isThreeOfAKind()
Pre Condition:
	totalArr is not empty and sortRiver() has run
Post Condition:
	Returns true if a Three of a kind is found
*/

bool poker::isThreeOfAKind()
{
	int count = 0;
	for(int i = 0; i < 3;i++)
	{
		for(int m = 1; m < 3; m++)
		{
			if(totalArr[i]->weight == totalArr[i+m]->weight)
			{
				count++;
			}
			
		}
	}
	if(totalArr[4]->weight == totalArr[3]->weight && totalArr[3]->weight == totalArr[2]->weight)
	{
		return true;
	}
	if(count == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isFullHouse()
Function Description:
	This method checks the cards for a Full House
Example:
	poker OBJ;
	OBJ->isFullHouse()
Pre Condition:
	totalArr is not empty and sortRiver() has run
Post COndition:
	Returns ture if Full House is found
*/

bool poker::isFullHouse()
{
	/*
	int count = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int m = 1; m<3; m++)
		{
			if(totalArr[i]->weight == totalArr[i+m]->weight)
			{
				count++;
			}
		}
		if(i == 0)
		{
			if(totalArr[i+3]->weight == totalArr[i+4]->weight && totalArr[i+3]->weight != totalArr[i+2]->weight)
			{
				count++;
			}
		}
		if(i == 2)
		{
			if(totalArr[i-2]->weight == totalArr[i-1]->weight && totalArr[i-1]->weight!= totalArr[i]->weight)
			{
				count++;
			}
		}
		i++;
	}

	if(count == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/

	if(totalArr[0]->weight == totalArr[1]->weight && totalArr[1]->weight == totalArr[2]->weight)
	{
		if(totalArr[3]->weight == totalArr[4]->weight && totalArr[3]->weight != totalArr[2]->weight)
		{
			return true;
		}
	}
	else if(totalArr[2]->weight == totalArr[3]->weight && totalArr[3]->weight == totalArr[4]->weight)
	{
		if(totalArr[0]->weight == totalArr[1]->weight && totalArr[1]->weight != totalArr[2]->weight)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isTwoPair()
Function Description:
	This method searches the cards for a Two Pair
Example: 
	poker OBJ;
	OBJ->isTwoPair()
Pre Condition:
	isFourOfAKind() isThreOfAKind() and sortRiver() has run
Post Condition:
	Returns true if Two Pair is found
*/

bool poker::isTwoPair()
{
	int count = 0;
	if(isFourOfAKind() == false && isThreeOfAKind() == false)
	{
		for(int i = 0; i<4; i++)
		{
			if(totalArr[i]->weight == totalArr[i+1]->weight)
			{
				count++;
			}
		}
	}
	if(count == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	bool poker::isOnePair()
Function Description:
	This method searches the cards for a pair of Jack or greater
Example:
	poker OBJ;
	OBJ->isOnePair()
Pre Condition:
	isFourOfAKind() isThreeOfAKind() isTwoPair() and sortRiver() has run
Post Condition:
	Returns true if a pair of Jacks or better is found
*/

bool poker::isOnePair()
{
	int count = 0;
	if(isFourOfAKind() == false && isThreeOfAKind() == false && isTwoPair() == false)
	{
		for(int i = 0; i < 4; i++)
		{
			if((stoi(totalArr[i]->weight) > 10 || stoi(totalArr[i]->weight) == 1 )&& totalArr[i]->weight == totalArr[i+1]->weight)
			{
				count++;
			}
		}
	}
	if(count == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Function Prototype:
	void poker::displayMenu()
Function Description:
	This method displays a menu of options
Example:
	poker OBJ;
	OBJ->displayMenu()
Pre Condition:
	None
Post Condition:
	Displays menu
*/

void poker::displayMenu()
{
	cout<<"|------------|"<<endl;
	cout<<"|  1.Bet x1  |"<<endl;
	cout<<"|  2.Bet x2  |"<<endl;
	cout<<"|  3.Bet x3  |"<<endl;
	cout<<"|            |"<<endl;
	cout<<"|  4.Rules   |"<<endl;
	cout<<"|  5.Quit    |"<<endl;
	cout<<"|------------|"<<endl;
}
/*
Function Prototype:
	void poker::handChecker(int i)
Function Description:
	This method finds the best hand by calling the hand functions in order from best to worst
Example:
	poker OBJ;
	OBJ->handChecker(menuCommand)
Pre Condition:
	All hand functions need to have run, sortRiver() needs to have run, menuCommand needs to be defined by input
Post Condition:
	Will print out the best hand combination possible
*/
void poker::handChecker(int i)
{
	cout << endl;
	if(isRoyalFlush() == true)
	{
		money = money + (250 * i);
		cout << "You have a Royal Flush" << endl;
	}
	else if(isStraightFlush() == true)
	{
		money = money + (50 * i);
		cout << "You have a Straight Flush" << endl;
	}
	else if(isFourOfAKind() == true)
	{
		money = money + (25 * i);
		cout << "You have a Four of a Kind" << endl;
	}
	else if(isFullHouse() == true)
	{
		money = money + (9 * i);
		cout << "You have a Full House" << endl;
	}
	else if(isFlush() == true)
	{
		money = money + (6 * i);
		cout << "You have a Flush" << endl;
	}
	else if(isStraight() == true)
	{
		money = money + (4 * i);
		cout << "You have a Straight" << endl;
	}
	else if(isThreeOfAKind() == true)
	{
		money = money + (3 * i);
		cout << "You have a Three of a Kind" << endl;
	}
	else if(isTwoPair() == true)
	{
		money = money + (2 * i);
		cout << "You have a Two Pair" << endl;
	}
	else if(isOnePair() == true)
	{
		money = money + (1 * i);
		cout << "You have Jacks or Better" << endl;
	}
	else
	{
		cout << "You have Nothing..." << endl;
	}
}

/*
Function Prototype:
	void poker::displayValues()
Function Description:
	This method displays a menu showing the values for the various hands implenting the multipliers based on size of bet
Example:
	poker OBJ:
	OBJ->dipslayValues()
Pre Condition:
	None
Post Condition:
	Menu of money values per hand is printed
*/

void poker::displayValues()
{
	cout << "------------------------------------" << endl;
	cout << "| Royal Flush   " << " | " << 250 << " | " << 500 << " | " << 750 << " | " << endl;
	cout << "| Straight Flush" << " | " << 50 << "  | " << 100 << " | " << 150 << " | " << endl;
	cout << "| Four of A Kind" << " | " << 25 << "  | " << 50 << "  | " << 75 << "  | " << endl;
	cout << "| Full House    " << " | " << 9 << "   | " << 18 << "  | " << 27 << "  | " << endl;
	cout << "| Flush         " << " | " << 6 << "   | " << 12 << "  | " << 18 << "  | " << endl;
	cout << "| Straight       " << "| " << 4 << "   | " << 8 << "   | " << 12 << "  | " << endl;
	cout << "| Three of a Kind" << "| " << 3 << "   | " << 6 << "   | " << 9 << "   | " << endl;
	cout << "| Two Pair      " << " | " << 2 << "   | " << 4 << "   | " << 6 << "   | " << endl;
	cout << "| Jacks or Better" << "| " << 1 << "   | " << 2 << "   | " << 3 << "   | " << endl;
	cout << "------------------------------------" << endl;
}

/*
Function Prototype:
	void poker::displayRules()
Function Description:
	This method displays the rules when the user requests it
Example:
	poker OBJ;
	OBJ->displayRules()
Pre Condition:
	menuCommand == 4
Post Condition:
	Prints rules
*/

void poker::displayRules()
{
	cout << "                Hello, Welcome to Jacks or Better Poker                " << endl;
	cout << "                          The rules are simple                         " << endl;
	cout << "     Every round you can bet 1 credit with a 1x, 2x, 3x Multiplier     " << endl;
	cout << "  You will then be dealt a hand and given the chance to discard cards  " << endl;
	cout << "                    To create the best hand possible                   " << endl;
	cout << "        To discard enter the number that corresponds to the card       " << endl;
	cout << "         Make sure to enter the cards for discard one at a time        " << endl;
	cout << "     When you have entered all the cards to be discarded press '6'     " << endl;  
	cout << "      You will then be dealt cards to replace those you discarded      " << endl;
	cout << "            To win all you need is a pair of Jacks or higher           " << endl;
	cout << "       The better the hand you have the more money you will make       " << endl;
	cout << "                               Good Luck!                              " << endl;
}

/*
Function Prototype:
	void poker::testRiver()
Function Description:
	This method was a test method to test specific instances of hands
Example:
	poker OBJ;
	OBJ->testRiver()
Pre Condition:
	None
Post Condition:
	Rewrites the cards to pre set cards
*/

void poker::testRiver()
{
	totalArr[0]->weight = "1";
	totalArr[1]->weight = "1";
	totalArr[2]->weight = "2";
	totalArr[3]->weight = "3";
	totalArr[4]->weight = "4";

	totalArr[0]->suit = "♦";
	totalArr[1]->suit = "♦";
	totalArr[2]->suit = "♦";
	totalArr[3]->suit = "♦";
	totalArr[4]->suit = "♦";
	
	
}
