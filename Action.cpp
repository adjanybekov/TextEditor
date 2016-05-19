#include "Action.h"

Action::Action(ActionType aType, int cursor_row, int cursor_col, char param)
{
	crow = cursor_row;
	ccol = cursor_col;
	at = aType;
	p = param;
}

ActionType Action::getType()
{
	return at;
}

int Action::getCol()
{
	return ccol;
}

int Action::getRow()
{
	return crow;
}

char Action::getParam()
{
	return p;
}