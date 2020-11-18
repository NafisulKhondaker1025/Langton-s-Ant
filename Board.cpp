#include "Board.hpp"
#include "Gary.hpp"
#include <fstream>

Board::Board(unsigned int x) {
	if ((x % 2) == 0) {
		std::cout << "Board dimension must be an odd number!! Got " << x << " and adding 1 to equal " << x + 1 << std::endl;
		x += 1;
		dim = x;
	}
	else {
		dim = x;
	}
	board = new Cell* [dim];
	for (int i = 0; i < dim; i++) {
		board[i] = new Cell [dim];
	}
}

void Board::setOutputFilename(std::string x) {
	fileName = x;
}

void Board::move_gary(unsigned int s) {
	std::ofstream outp(fileName);
	Gary gary(dim);

	if (outp.is_open()) {
		outp << "[Gary Location] {" << gary.Gary::get_row() << ", " << gary.Gary::get_col() << "} [Gary Orientation] " << gary.Gary::get_orientation_string();
		for (int i = 0; i < dim; ++i) {
			outp << " [Row " << i << "] ";
			for (int j = 0; j < dim; ++j) {
				if (j == (dim - 1)) {
					outp << board[i][j].Cell::get_color_string();
				}
				else {
					outp << board[i][j].Cell::get_color_string() << " ";
				}
			}
		}
		outp << "\n";
	}
	else {
		std::cout << "[Gary Location] {" << gary.Gary::get_row() << ", " << gary.Gary::get_col() << "} [Gary Orientation] " << gary.Gary::get_orientation_string();
		for (int i = 0; i < dim; ++i) {
			std::cout << " [Row " << i << "] ";
			for (int j = 0; j < dim; ++j) {				
				if (j == (dim - 1)) {
					std::cout << board[i][j].Cell::get_color_string();
				}
				else {
					std::cout << board[i][j].Cell::get_color_string() << " ";
				}
			}
		}
		std::cout << "\n";
	}

	while (s > 0) {
		gary.move(&board[gary.Gary::get_row()][gary.Gary::get_col()]);
		//output to file or console
		if (outp.is_open()) {
			outp << "[Gary Location] {" << gary.Gary::get_row() << ", " << gary.Gary::get_col() << "} [Gary Orientation] " << gary.Gary::get_orientation_string();
			for (int i = 0; i < dim; ++i) {
				outp << " [Row " << i << "] ";
				for (int j = 0; j < dim; ++j) {
					if (j == (dim - 1)) {
						outp << board[i][j].Cell::get_color_string();
					}
					else {
						outp << board[i][j].Cell::get_color_string() << " ";
					}
				}
			}
			outp << "\n";
		}
		else {
			std::cout << "[Gary Location] {" << gary.Gary::get_row() << ", " << gary.Gary::get_col() << "} [Gary Orientation] " << gary.Gary::get_orientation_string();
			for (int i = 0; i < dim; ++i) {
				std::cout << " [Row " << i << "] ";
				for (int j = 0; j < dim; ++j) {
					if (j == (dim - 1)) {
						std::cout << board[i][j].Cell::get_color_string();
					}
					else {
						std::cout << board[i][j].Cell::get_color_string() << " ";
					}
				}
			}
			std::cout << "\n";
		}
		--s;
	}
	outp.close();
}