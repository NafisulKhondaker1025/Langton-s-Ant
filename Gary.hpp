#ifndef HAVEYOUSEENTHSISNAIL_GARY
#define HAVEYOUSEENTHSISNAIL_GARY

#include "Cell.hpp"

enum orientation { up, right, down, left };

class Gary {
public:
	//default constructor to initialize the starting location of Gary to be in the middle
	Gary(unsigned int);
	
	//functions to get the row and column number of the cell gary is currently in
	unsigned int get_row();
	unsigned int get_col();

	//function to get orientation of gary
	orientation get_orientation();

	std::string get_orientation_string();

	//function to move gary
	void move(Cell*);

private:
	unsigned int g_row;
	unsigned int g_col;
	orientation g_or;
	unsigned int dim;
};
#endif
