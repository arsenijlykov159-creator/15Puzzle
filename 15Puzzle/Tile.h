#if !defined(TILE_H)
#define TILE_H

#include <iostream>
#include <cstdint>
#include <utility>


class Tile {
public:
	using Data = std::int8_t;

private:
	Data m_data{};

public:
	Tile() = default;

	explicit constexpr Tile(Data data) : m_data{data} {}

	constexpr Tile(const Tile& other_tile) : m_data{ other_tile.m_data } {}

	constexpr void set_data(Data data) { m_data = data; }

	constexpr int get_data() const { return m_data; }

	constexpr bool isEmpty() const { return (m_data == 0); }


	friend bool operator==(const Tile& t1, const Tile& t2) { return t1.m_data == t2.m_data; }

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

};





#endif