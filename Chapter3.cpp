#include "Chapter3.h"

Chapter3::Chapter3() {}

struct wordData {
	std::string word;
	std::string hint;
};

/// <summary>
/// Add scoring system to Word Jumble Game. Score is based of the length of the word and score penalty is given when player uses hint
/// </summary>
void Chapter3::startExercise1() {
	const int numWords = 5;
	const int numFields = 2;

	const wordData words[numWords][numFields] = {
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % numWords);
    std::string theWord = words[choice]->word;  // word to guess
    std::string theHint = words[choice]->hint;  // hint for word

    std::string jumbleWord = theWord;  // jumbled version of word
    int length = jumbleWord.size();
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumbleWord[index1];
        jumbleWord[index1] = jumbleWord[index2];
        jumbleWord[index2] = temp;
    }

    std::cout << "\t\t\tWelcome to Word Jumble!\n\n";
    std::cout << "Unscramble the letters to make a word.\n";
    std::cout << "Enter 'hint' for a hint.\n";
    std::cout << "Enter 'quit' to quit the game.\n\n";
    std::cout << "The jumble is: " << jumbleWord;

    std::string guess;
    //======= scoring system =======
    int score = theWord.length(); 
    int tries = 0;
    bool isHintUsed = false;
    const int hintPenalty = 2; //score penalty for using hint
    do
    {
        std::cout << "\n\nYour guess: ";
        std::cin >> guess;
        tries++;
        if (guess == "hint")
        {
            tries--; //assume that asking for hint is not counted as a try
            std::cout << theHint;
            if (!isHintUsed)
            {
                isHintUsed = true;
                score -= hintPenalty;
            }
        }
        else if ((guess != theWord) && (guess != "quit"))
        {
            std::cout << "Sorry, that's not it.";
            score--;
        }
    } while ((guess != theWord) && (guess != "quit"));

    if (guess == theWord)
    {
        std::cout << "You guessed it! You got it in " << tries;

        if  (tries > 1) std::cout << " tries\n";
        else {
            std::cout << " try!";
            if (!isHintUsed)
            {
                std::cout << " And without using hint too, impressive!";
            }
            std::cout << '\n';
        }
        
        std::cout << "\nYour score is: " << score <<'\n';
        if (isHintUsed)
            std::cout << "Try to guess it without using the hint next time to get better score.\n";
        if (tries > 1)
            std::cout << "Also try to guess it in fewer tries to get better score\n";

        std::cout << "\nThank you for playing!\n";
    }
}