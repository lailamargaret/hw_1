#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;



// Global constants (if any)

// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	//seed random numbers
	srand((int)time(0));


	/* --STATEMENTS-- */

	/*Card c;
	cout << c.get_english_rank()<< endl;
	cout << c.get_spanish_rank() << endl;
	cout << c.get_english_suit() << endl;
	cout << c.get_spanish_suit() << endl;
	Player me(100);*/

	Player user(100);
	std::cout << "You have $" << user.money << endl;

	//establish the bet
	int bet = 0;
	cout << "Enter your bet: $";
	cin >> bet;
	while (bet > user.money) {
		cout << "Please enter a bet that is less than or equal to your current total ($" << user.money << "). \nEnter your bet: $";
		cin >> bet;
		cout << "\n\n";
	}

	//Start playing the game
	Player dealer(900);
	dealer.hit();
	
	user.hit();
	cout << "\nYour card is: \n";
	user.print_hand();
	cout << "Your total is " << user.get_hand_value() << endl; 
	cout << endl;

	cout << "\nThe dealer has: \n";
	dealer.print_hand();
	cout << "The dealer's total is " << dealer.get_hand_value() << endl;
	cout << endl;



	//int user_hand_value = user.get_hand_value();
	if (user.get_hand_value() < 7.5) {
		char ask_hit;
		cout << "Would you like another card? (Type y/n): ";
		cin >> ask_hit;
		while (ask_hit == 'y' || ask_hit == 'Y' && user.get_hand_value() < 7.5) {
			user.hit();
			cout << "\nYour cards are: \n";
			user.print_hand();
			cout << "Your total is now " << user.get_hand_value() << endl;
			cout << endl;
			if (user.get_hand_value() >= 7.5)
				break;
			else {
				cout << "Would you like another card? (Type y/n): ";
				cin >> ask_hit;
			}
		}
	}

	//Player busts
	if (user.get_hand_value() > 7.5) {
		cout << "You busted.\n";
	}

	//Dealer draws
	while (dealer.get_hand_value() < 5.5) {
		cout << "\nThe dealer draws a new card.\n\n";
		dealer.hit();
		cout << "The dealer has: \n";
		dealer.print_hand();
		cout << "The dealer's total is " << dealer.get_hand_value() << endl;
		cout << endl;
		if (dealer.get_hand_value() > 7.5)
			cout << "The dealer busted.\n";
	}

	return 0;
}
