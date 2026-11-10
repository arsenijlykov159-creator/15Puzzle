#include <iostream>
#include "Tile.h"




int main() {

	Tile tile1{ 10 };
	Tile tile2{ 8 };
	Tile tile3{};
	Tile tile4{ 1 };

	Tile tile5{ 5 };
	Tile tile6{ 12 };
	Tile tile7{ 9 };
	Tile tile8{ 11 };

	std::cout << "0123456789ABCDEF\n"; 

	std::cout << tile1 << tile2 << tile3 << tile4 << '\n' << tile5 << tile6 << tile7 << tile8 << '\n';

	std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';

	std::cout << "Tile 2 has number: " << tile2.get_data() << "\nTile 4 has number: " << tile4.get_data() << '\n';





	return 0;
}