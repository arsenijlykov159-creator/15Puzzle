#include "UserInput.h"



namespace Input {

	bool isValidCommand(char command) {
		for (auto element : valid_command) {
			if (command == element) return true;
		}

		return false;
	}

	char getCommandFromUser() {
		while (true) {
			char input{};
			std::cin >> input;

			bool result{ std::cin };
			std::cin.clear();
			ignoreLine();

			if (result && isValidCommand(input)) return input;
			else std::cerr << "Invalid input!\n";
		}
	}


}