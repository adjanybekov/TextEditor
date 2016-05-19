#ifndef _ACTION_H_
#define _ACTION_H_

enum ActionType
{
	INSERT_CHAR,
	DEL,
	BACKSPACE,
	INSERT_LINE
};

class Action 
{
private:
	int crow;
	int ccol;
	char p;
	ActionType at;
	
public:

	Action(ActionType aType, int cursor_row, int cursor_col = 0, char param = 0);
	
	/* returns type of the action */
	ActionType getType();
	
	/* returns `cursor_row` variable given in the constructor. */
	int getRow();
	
	/* returns `cursor_col` variable given in the constructor. */
	int getCol();
	
	/* returns `param` variable given in the constructor. */
	char getParam();	
};

#endif