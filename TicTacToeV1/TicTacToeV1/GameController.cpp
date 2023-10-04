#include "GameController.h"
#include "Game.h"



GameController::GameController()
{
	board = make_shared<Board>();
	analzyer = make_shared<ResultAnalyzer>(board);
	players = make_shared<Player[]>(2);
}

void GameController::start()
{
	
	cout << "Welcome to the TicTacToe game " << endl;
	cout << "Enter first palyer name " << endl;
	string firstPlayerName;
	cin >> firstPlayerName;
	cout << "Enter second player name" << endl;
	string secondPlayerName;
	cin >> secondPlayerName;
	cout << "Lets ging the game ,all the best to :"
		<<firstPlayerName
		<< " and " << secondPlayerName<< endl;
	printBoard();
	
	players[0].setName(firstPlayerName);
	players[0].setMark(X);

	players[1].setName(secondPlayerName);
	players[1].setMark(O);

	game = make_unique<Game>(players, analzyer, board);

	while (game->getStatus() == "PROGRESS") {
		cout << "game in progress......." << endl;
		int cellPosition;
		cout << "current player is  :"<< game->getCurrentPlayer()->getName() << endl;
		cout << "Enter the cell positon " << endl;
		cin >> cellPosition;
		game->play(cellPosition,game->getCurrentPlayer()->getMark());

		printBoard();
	
	}
	cout << "Game is over :Winner is " << game->getCurrentPlayer()->getName();


}

void GameController::printBoard()
{
	for (int i = 0;i < 9;i++) {
		cout << Cell::markTypeToString(board->getCell(i).getMark()) << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << endl;

	}
}
