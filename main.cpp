#include <iostream>
#include <limits>		// for clearing input buffers
#include <string>
#include <string_view>




// --------------------
// FORWARD DECLARATIONS
// --------------------

std::string create_guess_word(size_t word_length);
void print_guess_word(std::string guess_word);
void print_target_word(std::string target_word);
void print_lives(int lives);
char get_guess_char();
bool is_char_in_string(char guess_char, std::string target_string);
std::string update_guess_word(char guess_char, std::string old_guess, std::string target_word);
void display_win_screen(std::string guess_word);
void display_lose_screen();


// DEBUG

template<class T>
void p(T msg)
{
	std::cout
		<< "DEBUG: ["
		<< msg
		<< "]\n";
}

template<class T>
void p(std::string preamble, T msg)
{
	std::cout
		<< "DEBUG: " + preamble + " ["
		<< msg
		<< "]\n";
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
	
		// Choose random word from dictionary file
	// *temp solution: input word to guess
	




	// Initialise required variables
	std::string target_word{ "hello" };  // <- TESTING ONLY
	std::string guess_word{ create_guess_word(target_word.length()) };
	char guess_char{};
	int lives{ 5 };
	bool game_over{ false };
	bool game_win{ false };

	// TEMP TEST SETTINGS
	//print_target_word(target_word);
	//guess_word = "ab cd";

	// ----- IN GAME -----
	// 
	
	while (game_over == false)
	{
		// Display core game screen
		std::cout << "\n\n\n\n\n";			// clear space to represent fresh game screen
	
				// print ASCII hangman
		print_lives(lives);
		print_guess_word(guess_word);





		// CORE GAME LOOP

		// Ask for guess
		guess_char = get_guess_char();
		// ADD FEATURE: keep track of guessed letters and disallow guessing the same letter twice

		// Evaluate whether guess is correct and progress appropriately
		if (!is_char_in_string(guess_char, target_word))
		{
			if (--lives > 0) std::cout << "Wrong guess! Try again!\n";
		}
		else
		{
			guess_word = update_guess_word(guess_char, guess_word, target_word);
			std::cout << "Correct guess! Well done!\n";
		}

		// final logic check whether game has been won or lost
		if (guess_word == target_word)
			game_win = true;

		if (lives <= 0 || game_win == true) 
			game_over = true;
		
	}
	

	if (game_win) display_win_screen(guess_word);
	else display_lose_screen();
	

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
	std::cout 
		<< "Target word is: \"" + target_word + "\" with length " 
		<< target_word.length() 
		<< "\n\n";
}



// create a string of spaces the length of inputted size_t value (hopefully the target word length).
std::string create_guess_word(size_t word_length)
{
	std::string guess_word{};

	for (size_t i{}; i < word_length; ++i)
	{
		guess_word += " ";
	}

	return guess_word;
}



// verbosely print underscored guess
void print_guess_word(std::string guess_word)
{
	std::string output{};

	// iterate over char's of guess to print letters or underscores
	for (size_t i{}; i < guess_word.length(); ++i)
	{
		if (guess_word[i] == ' ')
		{
			output += "___ ";
		}
		else 
		{
			output += "_";
			output += guess_word[i];
			output += "_ ";
		}
	}

	std::cout << output + "\n";
}



// verbosely print lives remaining
void print_lives(int lives)
{
	std::cout 
		<< "You have "
		<< lives
		<< " remaining\n";
}



// verbosely ask player to make a single character guess and return it
char get_guess_char()
{
	std::cout << "Enter guess: ";

	char guess_char{};
	std::cin >> guess_char;

	// clear remaining input buffer up to first of '\n' or the max number an int type can store characters
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');

	std::cout 
		<< "You guessed: " 
		<< guess_char 
		<< '\n';

	return guess_char;
}



// evaluate whether a character is in a string
bool is_char_in_string(char guess_char, std::string target_word)
{

	for (size_t i{}; i < target_word.length(); ++i)
	{
		if (guess_char == target_word[i]) return true;
	}

	return false;
}



// change correctly guessed characters in old guess from spaces to correct letter from target word
std::string update_guess_word(char guess_char, std::string guess_word, std::string target_word)
{
	for (size_t i{}; i < target_word.length(); ++i)
	{
		if (guess_char == target_word[i])
			guess_word[i] = guess_char;
	}

	return guess_word;
}



// display win screen
void display_win_screen(std::string guess_word)
{
	std::cout
		<< "Congratulations! \'"
		<< guess_word
		<< "\' was the correct answer!\n";
}



// display lose screen
void display_lose_screen()
{
	std::cout
		<< "Sadness! You took too many guesses and are now dead!\n";
}