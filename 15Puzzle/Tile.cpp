#include "Tile.h"



std::ostream& operator<<(std::ostream& out, const Tile& tile) {
	if (tile.m_data == 0) {
		out << "   ";
		return out;
	}

	if (tile.m_data > 0 && tile.m_data < 10) out << ' ';
	out << ' ' << static_cast<int>(tile.m_data);

	return out;
}