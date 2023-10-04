#pragma once
#include "Game.h"

class GameController
{
private:
	shared_ptr<Game> game;
	shared_ptr<Board> board;
	shared_ptr<Player[]> players;
	shared_ptr<ResultAnalyzer> analzyer;

public:
	GameController();
	void start();
	void printBoard();
};

