#include "defineMain.h"

#ifdef __S7_Quiz_Ex_Three__

#include <iostream>
#include <random>
#include <string>

// Flush input buffer
void ignore_line()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void print_message(const std::string& message)
{
	std::cout << message << std::endl;
}

bool check_guess(const int guess, const int correct_number)
{
	if (guess == correct_number)
	{
		print_message("Your guess is correct! You win.");

		return true;
	}

	if (guess > correct_number)
	{
		print_message("Your guess is too high.");
	}

	if (guess < correct_number)
	{
		print_message("Your guess is too low.");
	}

	return false;
}

int generate_random_number_in_range_x_to_y(const int x, const int y)
{
	std::random_device rd;

	std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

	std::mt19937 mt{ss};

	std::uniform_int_distribution random_number_in_range{x, y};

	return random_number_in_range(mt);
}

int get_user_guess(const int attempt_number)
{
	while (true)
	{
		printf("Guess #%d: ", attempt_number);
		int user_guess{0};
		std::cin >> user_guess;

		if (!std::cin)
		{
			std::cin.clear();

			ignore_line();

			print_message("Invalid input! Try again.");
		}
		else
		{
			ignore_line();

			return user_guess;
		}
	}
}

bool play_again()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		char user_answer{};
		std::cin >> user_answer;

		if (!std::cin)
		{
			std::cin.clear();

			ignore_line();

			print_message("Please answer with 'y' or 'n'.");
		}
		else
		{
			switch (user_answer)
			{
			case 'y':
				return true;
			case 'n':
				return false;
			default:
				{
					print_message("Unknown error.");
					return false;
				}
			}
		}
	}
}

void start_game()
{
	bool quit = false;
	bool game_started = false;
	bool game_over = false;
	int correct_number{generate_random_number_in_range_x_to_y(1, 100)};
	int guesses_remaining{7};
	int guess_attempt{1};

	while (!quit)
	{
		if (!game_started)
		{
			print_message(
				"Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess the number.");
			game_started = true;
		}

		if (const int user_guess{get_user_guess(guess_attempt)}; !check_guess(user_guess, correct_number))
		{
			++guess_attempt;
			--guesses_remaining;
		}
		else
		{
			game_over = true;
		}

		if (guesses_remaining <= 0)
		{
			printf("Sorry, you lose. The correct answer was %d\n", correct_number);

			game_over = true;
		}

		if (game_over)
		{
			if (play_again())
			{
				game_started = false;
				game_over = false;
				correct_number = generate_random_number_in_range_x_to_y(1, 100);
				guesses_remaining = 7;
				guess_attempt = 1;
			}
			else
			{
				quit = true;
			}
		}
	}
}

int main()
{
	// Welcome user
	// Get guess
	// Reply to input
	// Determine game state (win, lose, playing)
	// If game over, ask to play again
	// If user enters y, restart game
	// If user enters n, thank them for playing
	// If user does not enter y / n, repeat the question
	start_game();

	return 0;
}

#endif
