#include <iostream>
#include "UserInput.h"
#include "Board.h"
#include "Direction.h"




int main() {

	Board board{};
	std::cout << board << '\n';

	std::cout << Direction::rand() << '\n';
	std::cout << Direction::rand() << '\n';
	std::cout << Direction::rand() << '\n';
	std::cout << Direction::rand() << '\n';

	while (true) {

		char input{ Input::getCommandFromUser() };

		if (input == 'q') {
			std::cout << "\n\nBye!\n\n";
			break;
		}

		std::cout << "Valid command: " << input << '\n';
	}


	return 0;
}