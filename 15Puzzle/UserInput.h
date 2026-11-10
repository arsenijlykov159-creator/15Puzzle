#if !defined(USERINPUT_H)
#define USERINPUT_H

#include <iostream>
#include <array>
#include <limits>
#include "Direction.h"


namespace Input {

	constexpr std::array valid_command{ 'w', 'a', 's', 'd', 'q' };

	bool isValidCommand(char command);

	inline void ignoreLine() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char getCommandFromUser();

	Direction toDirectional(char user_input);

}



#endif