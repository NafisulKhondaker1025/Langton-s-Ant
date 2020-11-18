#include "Board.hpp"
#include "Cell.hpp"
#include "Gary.hpp"
#include <string>

int main(int argc, char** argv) {

	std::string fileName;
	unsigned int boardSize;
	unsigned int steps;

	if (argc == 3) {
		boardSize = atoi(*(argv + 1));
		steps = atoi(*(argv + 2));
	}
	else if (argc == 4) {
		boardSize = atoi(*(argv + 1));
		steps = atoi(*(argv + 2));
		fileName = *(argv + 3);
	}



	Board board(boardSize);
	board.setOutputFilename(fileName);
	board.move_gary(steps);

	return 0;
}