

#include "Cell.h"
#include "Board.h"


Board::Board()
{
	this->cells = make_unique<Cell[]>(9);
}

bool Board::isBoardFull()
{
	for (int i = 0;i < 9;i++) {
		if (this->cells[i].isEmpy())
			return false;
	}

	return true;
}

bool Board::isBoardEmpty()
{
	for (int i = 0;i < 9;i++) {
		if (this->cells[i].isEmpy())
			continue;
		return false;
	}


	 return true;
}

void Board::markCell(int cellPosition,MarkType markType)
{
	this->cells[cellPosition].setMark(markType);
	
}

Cell& Board::getCell(int cellPosition)
{
	return this->cells[cellPosition];
}
