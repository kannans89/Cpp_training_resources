#pragma once
#include "CommonHeader.h"
#include "Player.h"
#include "ResultAnalyzer.h"
#include "Board.h"
#include  "Cell.h"

class Game
{
private:
	shared_ptr<Player[]> players;
	shared_ptr<ResultAnalyzer> analyzer;
	shared_ptr<Board> board;
	string status;
	shared_ptr<Player> currentPlayer;

public:
	Game(shared_ptr<Player[]> players, shared_ptr<ResultAnalyzer> analyzer, shared_ptr<Board> board);
 
	inline shared_ptr<Player> getCurrentPlayer() {
		return currentPlayer;
	}

	inline string getStatus() {
		return status;
	}
	inline shared_ptr<Board> getBoard() { return board; }
	void play(int cellPosition, MarkType mark);
};

