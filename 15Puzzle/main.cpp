#include <iostream>
#include "UserInput.h"
#include "Board.h"
#include "Direction.h"
#include "Point.h"
#include "Timer.h"



int main() {

	Board board{};
	board.randomBoard();
	std::cout << board << '\n';

	std::size_t total_move{ 0 };

	Timer timer{};
	int last_second{ 0 };

	while (true) {

		std::cout << "Enter a move: ";
		char input{ Input::getCommandFromUser() };

		if (input == 'q') {
			std::cout << "\n\nBye!\n\n";
			break;
		}

		using enum Direction::Dir;

		Direction::Dir current_direction{Direction::convertToDir(input)};

		if (!board.moveTile(current_direction)) std::cout << "Wrong move!\n";
		else ++total_move;

		std::cout << board << '\n';
		std::cout << "Total move: " << total_move << '\n';

		int current_second = static_cast<int>(timer.elapsed());

		if (current_second > last_second) {
			last_second = current_second;
			std::cout << "Total time: : " << last_second << " second" << std::flush << '\n';
		}

		if (board.isBoardCorrect()) {
			std::cout << "\n\n__________You won!!!__________\n\n";
			break;
		}
	}


	return 0;
}