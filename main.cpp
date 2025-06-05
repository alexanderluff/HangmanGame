#include <iostream>
#include <string>

std::string create_guess(int word_length);
void print_guess(int word_length);
void print_guess(int word_length, std::string current_guesses);




int main()
{

	// Start game
	std::cout << "Welcome to Hangman!\n";



	std::string target_word{ "hello" };

	std::string guess{ create_guess(target_word.length()) };

	std::cout << "Target word is: \"" + target_word + "\" with length " << target_word.length() << ".\n";
	std::cout << "Guess length is " << guess.length() << " characters long.\n";

	print_guess(guess.length());




	return 0;
}



// create a string of spaces the length of inputted int value (hopefully the target word length).
std::string create_guess(int word_length)
{
	std::string guess{};

	for (int i{}; i < word_length; ++i)
	{
		guess += " ";
	}

	return guess;
}

// print only underscores of the length of a word.
void print_guess(int word_length)
{
	std::string underscores{};

	for (int i{}; i < word_length; ++i)
	{
		underscores += " _";
	}

	std::cout << underscores + "\n";
}

// overload of single parameter equivalent to handle adding guessed letters in too.
void print_guess(int word_length, std::string current_guesses)
{
	//
}