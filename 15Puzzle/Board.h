#if !defined(BOARD_H)
#define BOARD_H

#include <iostream>
#include <array>
#include <cassert>
#include "Tile.h"
#include "Direction.h"
#include "Point.h"



class Board {
public:
	using Size = std::size_t;

private:
	static constexpr Size consoleLines{ 25 };

	static constexpr Size tileCount{ 16 };
	static constexpr Size rowCount{ 4 };

	std::array<Tile, tileCount> m_data{};

	Point getClearPoint() const {
		for (Size i{ 0 }; i < rowCount; ++i) {
			for (Size j{ 0 }; j < rowCount; ++j) {
				if (m_data[i * rowCount + j].isEmpty()) return Point{ i, j };
			}
		}

		assert(0 && "No zero-tile is the board!");
		return Point{ static_cast<Point::Index>(-1), static_cast<Point::Index>(-1) };
	}

	bool isInBoard(const Point& p) {
		auto coordinates{ p.getIndexes() };
		std::cout << coordinates.first << ' ' << coordinates.second << '\n';
		std::cout << ((coordinates.first < rowCount - 1) && (coordinates.first >= 0) && (coordinates.second < rowCount - 1) && (coordinates.second >= 0)) << '\n';
		return (coordinates.first <= rowCount - 1 && coordinates.first >= 0 && coordinates.second <= rowCount - 1 && coordinates.second >= 0);
	}

public:

	Board();

	const Tile* operator[](Size index) const;

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

	

	bool moveTile(const Direction& d);

};






#endif