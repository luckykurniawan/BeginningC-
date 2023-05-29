#include "Chapter2.h"

Chapter2::Chapter2() {
}

int askNumber(std::string text, int lowVal, int highVal);

/// <summary>
/// Change difficulty from Menu Chooser program to enumeration
/// </summary>
void Chapter2::startExercise1() {
	std::cout << "Difficulty levels\n\n";
	std::cout << "1 - Easy\n";
	std::cout << "2 - Normal\n";
	std::cout << "3 - Hard\n\n";

	int choice;

	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case Easy:
		std::cout << "You picked Easy.\n";
		break;
	case Normal:
		std::cout << "You picked Normal.\n";
		break;
	case Hard:
		std::cout << "You picked Hard.\n";
		break;
	default:
		std::cout << "Illegal choice\n";
		break;
	}
}
/// <summary>
/// Guess My Number but the player give the number to be guessed
/// </summary>
void Chapter2::startExercise3() {
	const int lowValue = 1, highValue = 100; //low and high value of guess range
	const int outDelay = 1; //in seconds
	const int switchRange = 20; //range to switch algorithm

	int tries = 0;
	int secretNumber = 0;
	int guess = 0;

	int lowGuessVal = lowValue, highGuessVal = highValue; //known low and high value by computer 

	std::cout << "\tWelcome to Computer Guess My Number\n\n";

	secretNumber = askNumber("Enter number for the computer to guess", lowValue, highValue);

	//===== generator for normal distribution rng =====
	std::default_random_engine generator;
	generator.seed(static_cast<unsigned int>(time(0))); //seeding the generator
	//=================================================
	
	//computer guess the number
	do
	{
		std::cout << "Guessing...\n";
		if (highGuessVal - lowGuessVal < switchRange)
		{
			//================== using midrange value  ==================
			guess = static_cast<int>((lowGuessVal + highGuessVal) / 2);
			//=============================================================
		}
		else {
			//============================ using normal distribution rng ============================
			// using normal distribution so the guess is not the same all the time
			// while ensuring higher chance of picking value around the midrange 
			std::normal_distribution<double> distribution(((lowGuessVal + highGuessVal) / 2), 2.0);
			do
			{
				guess = static_cast<int>(distribution(generator));
			} while (guess < lowGuessVal || guess > highGuessVal);
			//=======================================================================================
		}
		
		//delay the output to simulate thinking
		std::this_thread::sleep_for(std::chrono::seconds(outDelay));

		tries++;
		std::cout << guess << ".\n";
		if (guess < secretNumber)
		{
			lowGuessVal = guess + 1; //set guess number + 1 as new low range value
			std::cout << "Too Low.\n\n";
		}
		else if (guess > secretNumber)
		{
			highGuessVal = guess - 1; //set guess number - 1 as new high range value
			std::cout << "Too High.\n\n";
		}
		else {
			std::cout << "Guessed it. Got it in " << tries << " tries\n";
		}
	} while (guess != secretNumber);
}

void Chapter2::startGuessMyNumber() {
	const int lowValue = 1, highValue = 100;

	srand(static_cast<unsigned int>(time(0))); //seeding rng

	int secretNumber = rand() % 100 + 1; //random number between 1 - 100
	int tries = 0;
	int guess = 0;

	std::cout << "\tWelcome to Guess My Number\n\n";

	do
	{
		guess = askNumber("Enter a guess", lowValue, highValue);
		tries++;

			if (guess > secretNumber)
				std::cout << "You guessed too high!\n\n";
			else if (guess < secretNumber)
				std::cout << "You guessed too low!\n\n";
			else
				std::cout << "You guessed it! You got it in " << tries << " guesses!\n";		
	} while (guess != secretNumber);
}

int askNumber(std::string text, int lowVal, int highVal) {
	int answer = 0;
	do
	{
		std::cout << text << " between " << lowVal << "-" << highVal << ": ";
		std::cin >> answer;
		//user gave non-numeric input
		if (std::cin.fail()) {
			std::cout << "Please input numbers only!\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		//user input number outside the range 
		else if (answer < lowVal || answer > highVal)
		{
			std::cout << "Please input number between " << lowVal << "-" << highVal << "!\n\n";
		}
	} while (std::cin.fail() || answer < lowVal || answer > highVal);

	return answer;
}