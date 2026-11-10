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


	Direction toDirectional(char user_input) {
		switch (user_input) {
		case 'w': return Direction{ Direction::Dir::up };
		case 'a': return Direction{ Direction::Dir::left };
		case 's': return Direction{ Direction::Dir::down };
		case 'd': return Direction{ Direction::Dir::down };
		default: return Direction{ Direction::Dir::unknown };
		}
	}

}