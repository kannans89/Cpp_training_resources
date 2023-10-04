#include "Game.h"

Game::Game(shared_ptr<Player[]> players, shared_ptr<ResultAnalyzer> analyzer, shared_ptr<Board> board)
{
	this->players = players;
	this->analyzer = analyzer;
	this->board = board;
	this->currentPlayer = 
		make_shared<Player>(players[0].getName(),players[0].getMark());
	status = "PROGRESS";
}

void Game::play(int cellPosition, MarkType mark)
{
	board->markCell(cellPosition, mark);
	status=analyzer->analyzeTheResult();
	if (status == "WIN" or status == "DRAW")
		return;

	if (currentPlayer->getName() == players[0].getName())
		this->currentPlayer =
		make_shared<Player>(players[1].getName(), players[1].getMark());
	else
		if(currentPlayer->getName() == players[1].getName())
			this->currentPlayer =
			make_shared<Player>(players[0].getName(), players[0].getMark());
}
