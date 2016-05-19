#ifndef _LINE_H_
#define _LINE_H_

#include <cstdlib>

class Line {
private:
	char *buffer;//what it does 
	int size;
	int gapstart;
	int gapend;
	
public:

	/* Creates an empty line. */
	Line();
	
	/* - Inserts char `c` to the cursor position. 
	 * Then moves the cursor to right by 1. 
	 */
	void insert(char c);
	
	/* - Deletes the character at the cursor position.
	 * - Does nothing if there is no character at the cursor position.
	 */
	void del();
	
	/* - Moves the cursor to left by 1.
	 * Then deletes the character at the cursor position.
	 * - Does nothing if the cursor is at the beginning of the line. 
	 */
	void backspace();
	
	/* Returns the position of the cursor under 0-based numbering. */
	int getCursorPosition() const;
	
	/* Returns the length of the line. */
	int getLength() const;
	
	/* - Returns the character at the `idx`-th position. 
	 * - `idx` should be given under 0-based numbering.
	 */
	char getCharAt(int idx) const;	
	
	/* - Moves the cursor to left by 1.
	 * - Does nothing if the cursor is at the beginning of the line.
	 */
	void moveCursorLeft(); 
	/* - Moves the cursor to right by 1.
	 * - Does nothing if the cursor is at the end of the line.
	 */ 
	void moveCursorRight();	
	
	/* - Moves the cursor to the `idx`-th position.
	 * - `idx` should be given under 0-based numbering.
	 */
	void moveCursorTo(int idx);
};


#endif