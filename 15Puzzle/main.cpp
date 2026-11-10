#include <iostream>
#include "UserInput.h"
#include "Board.h"




int main() {

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