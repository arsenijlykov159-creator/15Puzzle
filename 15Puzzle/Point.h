#if !defined(POINT_H)
#define POINT_H

#include <cstddef>
#include <utility>
#include "Direction.h"


class Point {
public:
	using Index = std::size_t;

private:
	Index m_x{};
	Index m_y{};

public:

	Point(Index x, Index y) : m_x{ x }, m_y{ y } {}


	std::pair<Index, Index> getIndexes() const { return { m_x, m_y }; }

	friend bool operator==(const Point& p1, const Point& p2);

	Point getAdjacentPoint(const Direction& d) const;

	friend std::ostream& operator<<(std::ostream& out, const Point& p) {
		out << '{' << p.m_x << ' ' << p.m_y << '}';
		return out;
	}

};



#endif