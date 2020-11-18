#ifndef HAVEYOUSEENTHSISNAIL_BOARD
#define HAVEYOUSEENTHSISNAIL_BOARD

#include "Cell.hpp"
#include "Gary.hpp"


class Board {
public:
	//function to return dimensions of board and ccconvert dimensions to odd if even number is inputted
	Board(unsigned int);


	//function to move gary a certain number of steps
	void move_gary(unsigned int);

	//function to creat output file pointer
	void setOutputFilename(std::string);

private:
	unsigned int dim;
	Cell** board;
	std::string fileName;
};


#endif
