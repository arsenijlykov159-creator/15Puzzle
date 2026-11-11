#include <iostream>
#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
#include "Point.h"



int main() {

	Board board{};
	std::cout << board << '\n';

	while (true) {

		std::cout << "Enter a move: ";
		char input{ Input::getCommandFromUser() };

		if (input == 'q') {
			std::cout << "\n\nBye!\n\n";
			break;
		}

		using enum Direction::Dir;

		Direction::Dir current_direction{};

		switch (input) {
		case 'w': 
			current_direction = up;
			break;
		case 'a':
			current_direction = left;
			break;
		case 's':
			current_direction = down;
			break;
		case 'd':
			current_direction = right;
			break;
		default:
			current_direction = unknown;
			break;
		}


		if (!board.moveTile(current_direction)) std::cout << "aaaaaaa\n";

		std::cout << board << '\n';
	}


	return 0;
}