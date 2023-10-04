#pragma once
#include "CommonHeader.h"
#include "Cell.h"
class Player
{
private:
	string name;
	MarkType mark=MarkType::EMPTY;
public:
	Player(string name, MarkType mark);
	Player() = default;
	inline string getName() { return name; }
	inline MarkType getMark() { return mark; }
	inline void setName(string name)  {
		this->name = name;
	};

	inline void setMark(MarkType mark) {
		this->mark = mark;
	};

};

