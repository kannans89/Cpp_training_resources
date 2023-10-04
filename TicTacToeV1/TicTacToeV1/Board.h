#pragma once

#include "Cell.h"


class Board {

private:
	unique_ptr<Cell[]> cells;

public :
	Board();
	bool isBoardFull();
	bool isBoardEmpty();
	void markCell(int cellPosition,MarkType type);
	Cell& getCell(int cellPosition);


};