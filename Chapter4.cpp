#include "Chapter4.h"

Chapter4::Chapter4(){}

void Chapter4::startHangman() {
	const int maxWrong = 8;

	std::vector<std::string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	std::random_shuffle(words.begin(), words.end());

	const std::string theWord = words[0];			// word to guess
	int wrong = 0;									// number of incorrect guesses
	std::string guessSoFar(theWord.size(), '*');	// word guessed so far
	std::string usedLetters = "";					// letters already guessed

	std::cout << "Welcome to Hangman. Good Luck!\n";

	// main loop

	while ((wrong < maxWrong) && (guessSoFar != theWord))
	{
        system("cls");

        std::cout << "You have " << (maxWrong - wrong);
        std::cout << " incorrect guesses left.\n";
        std::cout << "\nYou've used the following letters:\n" << usedLetters << '\n';
        std::cout << "\nSo far, the word is:\n" << guessSoFar << '\n';

        char guess;
        std::cout << "\n\nEnter your guess: ";
        std::cin >> guess;
        guess = toupper(guess); //make uppercase since secret word in uppercase
        while (usedLetters.find(guess) != std::string::npos)
        {
            std::cout << "\nYou've already guessed " << guess << '\n';
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            guess = toupper(guess);
        }

        usedLetters += guess;

        if (theWord.find(guess) != std::string::npos)
        {
            std::cout << "That's right! " << guess << " is in the word.\n";

            // update soFar to include newly guessed letter
            for (unsigned int i = 0; i < theWord.length(); ++i)
            {
                if (theWord[i] == guess)
                {
                    guessSoFar[i] = guess;
                }
            }
        }
        else
        {
            std::cout << "Sorry, " << guess << " isn't in the word.\n";
            wrong++;
        }
	}

    // shut down
    if (wrong == maxWrong)
        std::cout << "\nYou've been hanged!";
    else
        std::cout << "\nYou guessed it!";

    std::cout << "\nThe word was " << theWord << '\n';
}