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
		cout << endl;
	}

	//Start playing the game
	Player dealer(900);
	dealer.hit();
	
	cout << "\nThe dealer has: \n";
	dealer.print_hand();
	cout << endl;

	user.hit();
	cout << "Your card is: \n";
	user.print_hand();
	cout << endl;



	return 0;
}
