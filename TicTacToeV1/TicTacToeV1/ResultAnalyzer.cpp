#include "ResultAnalyzer.h"
#include "Cell.h"

string toStirng(MarkType m) {
    return Cell::markTypeToString(m);
}
bool ResultAnalyzer::checkHorizonal()
{
    string cell0 = toStirng(board->getCell(0).getMark());
    string cell1 = toStirng(board->getCell(1).getMark());
    string cell2 = toStirng(board->getCell(2).getMark());

    string cell3 = toStirng(board->getCell(3).getMark());
    string cell4 = toStirng(board->getCell(4).getMark());
    string cell5 = toStirng(board->getCell(5).getMark());

    string cell6 = toStirng(board->getCell(6).getMark());
    string cell7 = toStirng(board->getCell(7).getMark());
    string cell8 = toStirng(board->getCell(8).getMark());

    bool firstRowSame = false;
    if(cell0!="EMPTY" && cell1 != "EMPTY" && cell2 != "EMPTY")
      firstRowSame = (cell0 == cell1 && cell1 == cell2 );

    bool secondRowSame = false;
    if (cell3 != "EMPTY" && cell4 != "EMPTY" && cell5 != "EMPTY")
     secondRowSame = (cell3 == cell4 && cell4 == cell5);

    bool thirdRowSame = false;
    if (cell6 != "EMPTY" && cell7 != "EMPTY" && cell8 != "EMPTY")
    thirdRowSame=(cell6 == cell7 && cell7 == cell8);

   
    return (firstRowSame || secondRowSame || thirdRowSame);
}

bool ResultAnalyzer::checkVertical()
{
    string cell0 = toStirng(board->getCell(0).getMark());
    string cell3 = toStirng(board->getCell(3).getMark());
    string cell6 = toStirng(board->getCell(6).getMark());

    string cell1 = toStirng(board->getCell(1).getMark());
    string cell4 = toStirng(board->getCell(4).getMark());
    string cell7 = toStirng(board->getCell(7).getMark());

    string cell2 = toStirng(board->getCell(2).getMark());
    string cell5 = toStirng(board->getCell(5).getMark());
    string cell8 = toStirng(board->getCell(8).getMark());

    bool firstColumnSame = false;
    if (cell0 != "EMPTY" && cell3 != "EMPTY" && cell6 != "EMPTY")
     firstColumnSame = (cell0 == cell3 && cell3 == cell6);
   
    bool secondColumnSame = false;
    if (cell1 != "EMPTY" && cell4 != "EMPTY" && cell7 != "EMPTY")
     secondColumnSame = (cell1 == cell4 && cell4 == cell7);

    bool thirdColumnSame = false;
    if (cell2 != "EMPTY" && cell5 != "EMPTY" && cell8 != "EMPTY")
      thirdColumnSame = (cell2 == cell5 && cell5 == cell8);

    return (firstColumnSame || secondColumnSame || thirdColumnSame);
}

bool ResultAnalyzer::checkDiagonal()
{
    string cell0 = toStirng(board->getCell(0).getMark());
    string cell4 = toStirng(board->getCell(4).getMark());
    string cell8 = toStirng(board->getCell(8).getMark());

    string cell2 = toStirng(board->getCell(2).getMark());
  //  string cell4 = Cell::markTypeToString(board->getCell(4).getMark());
    string cell6 = toStirng(board->getCell(6).getMark());

    bool leftDiagonalSame = false;
    if (cell0 != "EMPTY" && cell4 != "EMPTY" && cell8 != "EMPTY")
      leftDiagonalSame = (cell0 == cell4 && cell4 == cell8);

    bool rightDiagonalSame = false;
    if(cell2 != "EMPTY" && cell4 != "EMPTY" && cell6 != "EMPTY")
     rightDiagonalSame = (cell2== cell4 && cell4==cell6);

    return (leftDiagonalSame || rightDiagonalSame);
}

ResultAnalyzer::ResultAnalyzer(shared_ptr<Board> board)
{
    this->board = board;
}


string ResultAnalyzer::analyzeTheResult()
{
   
    if (checkHorizonal() || checkVertical() || checkDiagonal())
        return "WIN";
    else if (board->isBoardFull())
        return "DRAW";
    else return  "PROGRESS";
}
