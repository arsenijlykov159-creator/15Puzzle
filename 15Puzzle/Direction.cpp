#include "Direction.h"




Direction Direction::operator-() const {
	if (m_direction == Dir::up) return Direction{ Dir::down };
	if (m_direction == Dir::down) return Direction{ Dir::up };
	if (m_direction == Dir::right) return Direction{ Dir::left };
	if (m_direction == Dir::left) return Direction{ Dir::right };

	return Direction{ Dir::unknown };
}


Direction Direction::rand() {
	return Direction{ static_cast<Dir>(Rand::get(1, 4)) };
}


std::ostream& operator<<(std::ostream& out, const Direction& d) {
	out << Direction::convertToStr(d);

	return out;
}