#if !defined(BOARD_H)
#define BOARD_H

#include <iostream>
#include <array>
#include <cassert>
#include "Tile.h"



class Board {
public:
	using Size = std::size_t;

private:
	static constexpr Size consoleLines{ 25 };

	static constexpr Size tileCount{ 16 };
	static constexpr Size rowCount{ 4 };

	std::array<Tile, tileCount> m_data{};

public:

	constexpr Board();

	constexpr const Tile* operator[](Size index) const;

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

};






#endif