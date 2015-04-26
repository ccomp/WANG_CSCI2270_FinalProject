#ifndef POKER_H
#define POKER_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct card
{
	std::string suit;
	std::string weight;
	bool dealt = false;

};

class poker
{
	public:
		void displayTable();
		card* assignCards();
		void displayTitle();
		void resetDeck();
		int bet();
		void displayMenu();
		void setPot(int bet);
		void displayCards();
		void setPlayerCards();
		void aiHand();
		void printShit();
		void bubbleSort(std::string *array, int n);
		void whatAIHas();
		void hold();
		void sortRiver();
		bool isStraight();
		bool isFlush();
		bool isFourOfAKind();
		bool isRoyalFlush();
		bool isStraightFlush();
		bool isThreeOfAKind();
		bool isFullHouse();
		bool isTwoPair();
		bool isOnePair();
		void handChecker(int i);
		void displayValues();
		void displayRules();

		void testRiver();

		std::string userName ="";
		void setUserName(std::string name)
		{
			userName = name;
		}
		void setRiver(int num)
		{
			river = num;
		}
		int getRiver()
		{
			return river;
		}
		card* totalAIArr[7];
		void setMoney(int num)
		{
			money = money + num;
		}


		

	private:
		int num = 52;
		std::vector<int> stupidSolution;
		std::string Arr1[52] = {"♥","♥","♥","♥","♥","♥","♥","♥","♥","♥","♥","♥","♥","♦","♦","♦","♦","♦","♦","♦","♦","♦","♦","♦","♦","♦","♣","♣","♣","♣","♣","♣","♣","♣","♣","♣","♣","♣","♣","♠","♠","♠","♠","♠","♠","♠","♠","♠","♠","♠","♠","♠"};
		std::string Arr2[52] = {"2","3","4","5","6","7","8","9","10","11","12","13","1","2","3","4","5","6","7","8","9","10","11","12","13","1","2","3","4","5","6","7","8","9","10","11","12","13","1","2","3","4","5","6","7","8","9","10","11","12","13","1"};
		std::string*suitArr = Arr1;
		std::string*weightArr = Arr2;
		std::string *resetSuit= Arr1;
		std::string *resetWeight = Arr2;
		card* totalArr[5];
		//card* totalAIArr[7];

		card * riverArr[5];
		card * playerArr[2]; 
		card * ai1Arr[2];
		//card * ai2Arr[2];

		card* c1 = new card;
		card* c2 = new card;

		int river = 0;

		int money = 100;
		int pot = 0;

		int playerHighCard = 0;

};

#endif
