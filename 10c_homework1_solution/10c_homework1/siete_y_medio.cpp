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
void win(Player user, Player dealer, int bet);
void lose(Player user, Player dealer, int bet);


// Non member functions implementations (if any)
void win(Player user, Player dealer, int bet) {
	cout << "You win $" << bet << "!\n";
	user.money += bet;
	dealer.money -= bet;
	cout << "You now have $" << user.money << ".\n\n";
}

void lose(Player user, Player dealer, int bet) {
	cout << "You lose $" << bet << ".\n";
	user.money -= bet;
	dealer.money += bet;
	cout << "You now have $" << user.money << ".\n\n";
}

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
	Player dealer(900);
	std::cout << "You have $" << user.money << endl;

	do {
		user.clear_hand();
		dealer.clear_hand();
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
		if (int b = user.get_hand_value() < 7.5) {
			char ask_hit;
			cout << "Would you like another card? (Type y/n): ";
			cin >> ask_hit;
			while (ask_hit == 'y' || ask_hit == 'Y' && user.get_hand_value() < 7.5) {
				user.hit();
				cout << "\nYour cards are: \n";
				user.print_hand();
				cout << "Your total is now " << user.get_hand_value() << endl;
				cout << endl;
				if (int x = user.get_hand_value() >= 7.5)
					break;
				else {
					cout << "Would you like another card? (Type y/n): ";
					cin >> ask_hit;
				}
			}
		}

		bool user_bust = false;
		bool dealer_bust = false;

		//Player busts
		if (user.get_hand_value() > 7.5) {
			cout << "You busted.\n";
			user_bust = true;
		}

		//Dealer draws
		while (dealer.get_hand_value() < 5.5) {
			cout << "\nThe dealer draws a new card.\n\n";
			dealer.hit();
			cout << "The dealer has: \n";
			dealer.print_hand();
			cout << "The dealer's total is " << dealer.get_hand_value() << endl;
			cout << endl;
			if (dealer.get_hand_value() > 7.5) {
				cout << "The dealer busted.\n\n";
				dealer_bust = true;
			}
		}

		//User doesn't bust
			//dealer busts, user wins
			//dealer does not bust
				//high score wins
		if (!(user_bust)) {
			if (dealer_bust)
				win(user, dealer, bet);
			else
				if (user.get_hand_value() > dealer.get_hand_value())
					win(user, dealer, bet);
				else if (user.get_hand_value() < dealer.get_hand_value())
					lose(user, dealer, bet);
				else {
					cout << "It's a tie.\n";
					cout << "You still have $" << user.money << ".\n\n";
				}
		}

		//user busts
			//dealer busts
				//house advantage
			//dealer does not bust, dealer wins
		if (user_bust) {
			if (dealer_bust) {
				cout << "House advantage.\n";
				lose(user, dealer, bet);
			}
			else if (!dealer_bust)
				lose(user, dealer, bet);
		}
	} while (user.money > 0 && dealer.money > 0);




	return 0;
}
