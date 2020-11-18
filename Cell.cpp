#include "Cell.hpp"

Cell::Cell() {
	color = white;
}

CellColor Cell::get_color() {
	return color;
}

void Cell::change_color() {
	switch (color) {
	case white:
		color = black;
		break;
	case black:
		color = white;
		break;
	}
}

std::string Cell::get_color_string() {
	switch (color) {
	case white:
		return "0";
		break;
	case black:
		return "1";
		break;
	}
}