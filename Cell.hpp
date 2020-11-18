#ifndef HAVEYOUSEENTHSISNAIL_CELL
#define HAVEYOUSEENTHSISNAIL_CELL
#include <iostream>
#include <string>

// Declare an enumaration data type to store the Cell's color
enum CellColor { white, black };

// Declare the Cell Class
class Cell {
public:
	// Declare default constructor to initialize color to white
	Cell();

	// Declare member function getter for the color (get_color). Returns CellColor
	CellColor get_color(void);

	// Declare a member to flip the color (change_color)
	void change_color(void);

	// Declare a member to print the string for this color.
	// white = "0", black = "1"
	std::string get_color_string(void);

private:
	CellColor color;
};




#endif
