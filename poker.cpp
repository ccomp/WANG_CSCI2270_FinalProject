	/*
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

void poker::resetDeck()
{
	weightArr = resetSuit;
	suitArr = resetSuit;
	stupidSolution.clear();
	river = 0;
}

void poker::setPlayerCards()
{
	for(int i = 0; i < 5; i++)
	{
		riverArr[i] = assignCards();
	}

}



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
