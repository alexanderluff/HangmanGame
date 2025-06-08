#include <iostream>
#include <string>





// --------------------
// FORWARD DECLARATIONS
// --------------------

std::string create_guess(size_t word_length);
void print_guess(std::string guess);
void print_target_word(std::string target_word);


// DEBUG

template<class T>
void p(T msg)
{
	std::cout << "DEBUG: [";
	std::cout << msg;
	std::cout << "]\n";
}

template<class T>
void p(std::string preamble, T msg)
{
	std::cout << "DEBUG: " + preamble + " [";
	std::cout << msg;
	std::cout << "]\n";
}









// --------------
//      MAIN
// --------------


int main()
{

	// ----- OPEN PROGRAM -----

	// Start game
	std::cout << "Welcome to Hangman!\n";

	// Press any key to continue
	//


	// ----- MAIN MENU -----
	// 
	//		- Play Game
	//		- Difficulty
	//		- Exit


	// ----- NEW GAME -----

	// Initialize game with chosen settings
	//


	// ----- IN GAME -----
	// 

	// Initialise required variables
	std::string target_word{ "hello" };
	std::string guess{ create_guess(target_word.length()) };
	p(guess);
	

	// Display core game screen

	print_target_word(target_word);

	guess = "ab cd";
	p(guess);
	print_guess(guess);
	
	

	// Print 


	// CORE GAME LOOP

	// Ask for first guess
	//

	std::cout << "Enter first guess";

	// Evaluate whether right or wrong
	//

	// IF 0 lives or game complete go to WIN or LOSE screen
	// ELSE repeat game loop
	//

	// Return to Main Menu
	//



	return 0;
}










// ------------------
//     FUNCTIONS
// ------------------


// print verbose target word and length
void print_target_word(std::string target_word)
{
	std::cout << "Target word is: \"" + target_word + "\" with length " << target_word.length() << "\n\n";
}


// create a string of spaces the length of inputted size_t value (hopefully the target word length).
std::string create_guess(size_t word_length)
{
	std::string guess{};

	for (size_t i{}; i < word_length; ++i)
	{
		guess += " ";
	}

	return guess;
}



// print underscored guess
void print_guess(std::string guess)
{
	std::string output{};

	// iterate over char's of guess to print letters or underscores
	for (size_t i{}; i < guess.length(); ++i)
	{

		if (guess[i] == ' ')
		{
			output += "___ ";
		}
		else 
		{
			output += "_";
			output += guess[i];
			output += "_ ";
		}

	}

	std::cout << output + "\n";
}