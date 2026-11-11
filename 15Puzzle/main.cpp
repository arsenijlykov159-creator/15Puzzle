#include <iostream>
#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
#include "Point.h"



int main() {

	Board board{};
	board.randomBoard();
	std::cout << board << '\n';

	while (true) {

		std::cout << "Enter a move: ";
		char input{ Input::getCommandFromUser() };

		if (input == 'q') {
			std::cout << "\n\nBye!\n\n";
			break;
		}

		using enum Direction::Dir;

		Direction::Dir current_direction{Direction::convertToDir(input)};

		if (!board.moveTile(current_direction)) std::cout << "aaaaaaa\n";

		std::cout << board << '\n';
		if (board.isBoardCorrect()) {
			std::cout << "\n\n__________You won!!!__________\n\n";
			break;
		}
	}


	return 0;
}