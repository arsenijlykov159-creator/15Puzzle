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