#pragma once
#include "Board.h"
#include "CommonHeader.h"

class ResultAnalyzer
{
private:
    shared_ptr<Board> board;
    bool checkHorizonal();
    bool checkVertical();
    bool checkDiagonal();
public:
   explicit ResultAnalyzer(shared_ptr<Board> board);
   string  analyzeTheResult();


};

