#include "Gary.hpp"

Gary::Gary(unsigned int x) {
	dim = x;
	x = (x / 2);
	g_row = x;
	g_col = x;
	g_or = up;
}

unsigned int Gary::get_row(void) {
	return g_row;
}
unsigned int Gary::get_col(void) {
	return g_col;
}
orientation Gary::get_orientation(void) {
	return g_or;
}

std::string Gary::get_orientation_string(void) {
	switch (Gary::get_orientation()) {
	case up:
		return "up";
		break;
	case right:
		return "right";
		break;
	case down:
		return "down";
		break;
	case left:
		return "left";
		break;
	}
}

void Gary::move(Cell* x) {
	switch (x->Cell::get_color()) {
	case white:  //clockwise
		switch (Gary::get_orientation()) {
		case up:
			g_or = right;
			break;
		case right:
			g_or = down;
			break;
		case down:
			g_or = left;
			break;
		case left:
			g_or = up;
			break;
		}
		break;
	case black: //counterclockwise
		switch (Gary::get_orientation()) {
		case up:
			g_or = left;
			break;
		case right:
			g_or = up;
			break;
		case down:
			g_or = right;
			break;
		case left:
			g_or = down;
			break;
		}
		break;
	}
	
	//changing color
	x->Cell::change_color();
	
	//changing position
	switch (g_or) {
	case up:
		if (g_row == 0) {
			g_row = (dim - 1);
		}
		else {
			--g_row;
		}
		break;
	case down:
		if (g_row == (dim - 1)) {
			g_row = 0;
		}
		else {
			++g_row;
		}
		break;
	case left:
		if (g_col == 0) {
			g_col = (dim - 1);
		}
		else {
			--g_col;
		}
		break;
	case right:
		if (g_col == (dim - 1)) {
			g_col = 0;
		}
		else {
			++g_col;
		}
		break;
	}
}