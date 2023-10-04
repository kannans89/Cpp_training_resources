

#include "Cell.h"
#include "CommonHeader.h"
#include "Board.h"
#include "ResultAnalyzer.h"
#include "Player.h"
#include "Game.h"
#include "GameController.h"

void cellTestCases() {

	Cell cell;
	MarkType result = cell.getMark();
	cout << Cell::markTypeToString(result) << endl;
	cell.setMark(MarkType::X);
	cout << Cell::markTypeToString(cell.getMark()) << endl;


}

void printBoard(Board& b) {
	for (int i = 0;i < 9;i++) {
		cout << Cell::markTypeToString(b.getCell(i).getMark()) << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << endl;

	}
}
void printBoard(shared_ptr<Board> b) {
	for (int i = 0;i < 9;i++) {
		cout << Cell::markTypeToString(b->getCell(i).getMark()) << "\t";
		if (i == 2 || i == 5 || i == 8)
			cout << endl;

	}
}

void boardTestCase1_fullBoardCheck() {

	Board b = {};
	b.markCell(0, MarkType::O);
	b.markCell(1, MarkType::X);
	b.markCell(2, MarkType::O);
	b.markCell(3, MarkType::O);
	b.markCell(4, MarkType::O);
	b.markCell(5, MarkType::O);
	b.markCell(6, MarkType::O);
	b.markCell(7, MarkType::O);
	b.markCell(8, MarkType::O);

	//cout << b.isBoardEmpty() << endl;
	cout << b.isBoardFull() << endl;
	printBoard(b);

}

void checkProgressResultCase() {
	auto b = make_shared<Board>();
	
	b->markCell(0, MarkType::O);
	b->markCell(1, MarkType::X);
	b->markCell(2, MarkType::O);
	b->markCell(3, MarkType::O);
	b->markCell(4, MarkType::X);
	b->markCell(5, MarkType::O);
	b->markCell(6, MarkType::X);
	b->markCell(7, MarkType::O);
	b->markCell(8, MarkType::EMPTY);

	ResultAnalyzer anlyzer(b);
	
	printBoard(b);

	cout << "result of analyziss is :" << anlyzer.analyzeTheResult() << endl;
	
}

void testCaseGameClass() {

	auto board = make_shared<Board>();
	auto analyzer = make_shared<ResultAnalyzer>(board);
	auto players = make_shared<Player[]>(2);
	players[0].setMark(MarkType::X);
	players[0].setName("varun");
	players[1].setMark(MarkType::O);
	players[1].setName("kannan");


	Game game(players, analyzer, board);
	cout << "current player is before play :" << game.getCurrentPlayer()->getName() << endl;
	game.play(0, MarkType::X);
	cout << "current player is after play :" << game.getCurrentPlayer()->getName() << endl;
	cout << "Game status is :" << game.getStatus() << endl;
	printBoard(board);



}

int main()
{
	//boardTestCase1_fullBoardCheck();
	//cellTestCases();
	//checkProgressResultCase();

	//testCaseGameClass();

	GameController controller;
	controller.start();
}

