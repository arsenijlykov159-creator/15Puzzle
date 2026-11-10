#if !defined(DIRECTION_H)
#define DIRECTION_H

#include <iostream>
#include <string_view>
#include "Rand.h"


class Direction {
public:
	enum Dir {
		unknown,
		up,
		down,
		left,
		right,
		max_Directions,
	};

	



private:
	Dir m_direction{};

	static std::string_view convertToStr(const Direction& d) {
		switch (d.m_direction) {
		case up: return "up";
		case down: return "down";
		case right: return "right";
		case left: return "left";
		default: return "unknown";
		}
	}

public:
	//constexpr explicit Direction(char user_input) {
	//	switch (user_input) {
	//	case 'w': 
	//		m_direction = Dir::up;
	//		return;
	//	case 'a':
	//		m_direction = Dir::left;
	//		return;
	//	case 's':
	//		m_direction = Dir::down;
	//		return;
	//	case 'd':
	//		m_direction = Dir::right;
	//		return;
	//	default:
	//		m_direction = Dir::unknown;
	//	}
	//}

	constexpr explicit Direction(Dir data) : m_direction{ data } {}

	Direction operator-() const;

	static Direction rand();

	friend std::ostream& operator<<(std::ostream& out, const Direction& d);
};



#endif