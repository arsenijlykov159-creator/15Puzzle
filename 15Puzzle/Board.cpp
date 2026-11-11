#include "Board.h"


Board::Board() {
	for (Size i{ 0 }; i < tileCount - 1; ++i) {
		m_data[i] = Tile{ static_cast<Tile::Data>(i + 1) };
	}

	m_data[tileCount - 1] = Tile{};
}


const Tile* Board::operator[](Size index) const {
	assert(index < rowCount && "Index is too large!");

	return &m_data[index * rowCount];
}


std::ostream& operator<<(std::ostream& out, const Board& board) {
	for (Board::Size i{ 0 }; i < board.consoleLines; ++i) {
		out << '\n';
	}

	for (Board::Size i{ 0 }; i < board.rowCount; ++i) {
		for (Board::Size j{ 0 }; j < board.rowCount; ++j) {
			out << board[i][j];
		}

		out << '\n';
	}

	return out;
}


bool Board::moveTile(const Direction& d) {
	Point current_clear_point{ getClearPoint() };
	Point next_point{ current_clear_point.getAdjacentPoint(-d) };

	if (!isInBoard(next_point)) return false;
	else {
		auto coordinates_clear_point{ current_clear_point.getIndexes() };
		auto coordinates_next_point{ next_point.getIndexes() };

		m_data[coordinates_clear_point.second * rowCount + coordinates_clear_point.first] = m_data[coordinates_next_point.second * rowCount + coordinates_next_point.first];
		m_data[coordinates_next_point.second * rowCount + coordinates_next_point.first] = Tile{ 0 };
	}

	return true;
}


void Board::randomBoard() {
	for (std::size_t _{ 0 }; _ < 1000; ++_) {
		moveTile(Direction::rand());
	}
}



bool Board::operator==(const Board& b) const {
	for (Size i{ 0 }; i < rowCount; ++i) {
		for (Size j{ 0 }; j < rowCount; ++j) {
			if ((*this)[i][j] != b[i][j]) return false;
		}
	}

	return true;
}
