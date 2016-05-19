
#ifndef _EDITOR_H_
#define _EDITOR_H_

#include <string>
#include <stack>
#include "Line.h"
#include "Action.h"
#include "LinkedNode.h"
#include "LinkedList.h"

class Editor {
private:
	LinkedList<Line> lines;
	std::stack<Action> history; /* user's action history */
	int cursor;		// current line number of the cursor.
public:	

	/* Default constructor.
	 * Since an editor cannot have less than 1 line, an empty line should be
	 * added in this constructor.
	 */	 
	Editor() {
		Line firstLine;
		lines.insertFirst(firstLine);
		cursor = 0;	
	}
	
	
	/* Inserts an empty line after the line that the cursor is at.
	 * After inserting the line, cursor points to newly inserted line
	 * While inserting, previous line should not be broken, meaning that
	 * previous line should stay unchanged and new line should be empty.
	 * After the insertion, INSERT_LINE action should be added to action 
	 * history.
	 */
	void insertLine();	
	
	/* Inserts characater _c_ to the line that the cursor is at by calling
	 * corresponding function from Line class. Then, INSERT_CHAR action is added
	 * to action history.
	 */
	void insertChar(char c);
	
	/* Calls corresponding function from Line class if there is a chacarter
		at the cursor position and saves the action to the history.
	 * if there is no character at the cursor position, function does nothing
	 */
	void del();
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	/* Calls corresponding function from Line class if there is a chacarter
		on the left of cursor position and saves the action to the history.
	 * if the cursor is at the beginning of the line, function does nothing. 
	 */
	void backspace();
	
	/* Reverts the last action If there is an action in the history stack.
	 * Revertable actions are:
	 	- backspacing a character
	 	- deleting a character
	 	- inserting a character
	 	- inserting a line
	 */
	void undo();
	
	/* Moves the cursor up by 1 if the cursor is not at the first line.
	 */
	void moveCursorUp();
	
	/* Moves the cursor down by 1 if the cursor is not at the last line.
	 */
	void moveCursorDown();
	
	/* Calls corresponding function from Line class
	 */	
	void moveCursorLeft();

	/* Calls corresponding function from Line class
	 */	
	void moveCursorRight();	
	
	/* Returns cursor row(global cursor) under 0-based numbering.
	 */
	int getCursorRow() const; 

	/* Returns cursor column(cursor of the line that global cursor is at) 
	 * under 0-based numbering.
	 */
	int getCursorCol() const;
	
	/* Returns line count of the editor
	 */
	int getLength() const;
	
	/* Returns the content of the idx-th line under 0-based numbering.
	 */
	std::string getLine(int idx) const;		
//
};

#endif
