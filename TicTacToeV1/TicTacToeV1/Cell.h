#pragma once
#include "CommonHeader.h"

enum  MarkType {
	X = 0, O = 1, EMPTY = 2

};

class Cell
{
private:
	MarkType mark;
	

public:
	Cell();
	 void setMark(MarkType mark);
	 MarkType getMark();
	 bool isEmpy();
	 static string markTypeToString(MarkType mark);
};

