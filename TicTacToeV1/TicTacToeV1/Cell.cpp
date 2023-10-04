#include "Cell.h"

#include "CommonHeader.h"


ostream& operator << (ostream& strm, MarkType tt)
{
	const string nameTT[] = { "X", "O", "EMPTY" };
	return strm << nameTT[tt];
}

string Cell::markTypeToString(MarkType mark)
{
	const string markTypes[] = { "X", "O", "EMPTY" };
	return markTypes[mark];
}


Cell::Cell() {
	this->mark = MarkType::EMPTY;
}

void Cell::setMark(MarkType mark) {
	if (this->isEmpy())
		this->mark = mark;
	else
		throw "cell already marked";
}

MarkType Cell::getMark() {
	return this->mark;
}
bool Cell::isEmpy() {
	return (this->mark == MarkType::EMPTY);
}
