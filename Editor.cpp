#include "Editor.h"
//#include <iostream>
//std::stack<string> mystack;


void Editor::insertLine(){
Line newLine;//crates Data
Action act(INSERT_LINE, cursor , lines.getNodeAt(cursor)->getData()->getCursorPosition());
history.push(act);
lines.insertNode( lines.getNodeAt(cursor), newLine);
cursor = cursor+1;
}


/* Inserts characater _c_ to the line that the cursor is at by calling
	 * corresponding function from Line class. Then, INSERT_CHAR action is added
	 * to action history.
	 */
void Editor::insertChar(char c){
	//if (/*There is a character next to the Cursor */) for delete 
	Action act(INSERT_CHAR, cursor , lines.getNodeAt(cursor)->getData()->getCursorPosition() ) ; 
	if(c == ' '){
		lines.getNodeAt(cursor)->getData()->insert(' ');
	}
	else
		lines.getNodeAt(cursor)->getData()->insert(c);
	history.push(act);

}

	/* Calls corresponding function from Line class if there is a chacarter
		at the cursor position and saves the action to the history.
	 * if there is no character at the cursor position, function does nothing
	 */
void Editor::del(){

	if(lines.getNodeAt(cursor)->getData()->getCursorPosition()+1!=0){//
		Action act(DEL, cursor , lines.getNodeAt(cursor)->getData()->getCursorPosition() ,  lines.getNodeAt(cursor)->getData()->getCharAt(lines.getNodeAt(cursor)->getData()->getCursorPosition())) ; 
		history.push(act);
		lines.getNodeAt(cursor)->getData()->del(); //geta char at cursor position! 
		
		
	}

}


void Editor::backspace(){
/*
	if(getCharAt(lines.getNodeAt(cursor)->getData()->getCursorPosition()-1)){
		line.getCursorPosition() = line.getCursorPosition()-1;
		line.getCharAt(cursor).del();
	}
	mystack.push('BACKSPACE');*/

	if(lines.getNodeAt(cursor)->getData()->getCursorPosition()!=0){//What is the line ??
		
		Action act(BACKSPACE, cursor , lines.getNodeAt(cursor)->getData()->getCursorPosition() ,  lines.getNodeAt(cursor)->getData()->getCharAt(lines.getNodeAt(cursor)->getData()->getCursorPosition()-1));
		history.push(act); 
		lines.getNodeAt(cursor)->getData()->backspace(); //geta char at cursor position! 	
	
	}
	
	
}

void Editor::undo(){ 
	if(!history.empty()){

	Action A(history.top().getType(), history.top().getRow() , history.top().getCol(), history.top().getParam());

	if(A.getType() == INSERT_LINE){


	
		lines.deleteNode(lines.getNodeAt(cursor));
		//cursor--;
		cursor = A.getRow();
		lines.getNodeAt(cursor)->getData()->moveCursorTo(A.getCol());

		history.pop();
	
		}
	else if(A.getType() == INSERT_CHAR){
		lines.getNodeAt(A.getRow())->getData()->moveCursorTo(A.getCol());
		lines.getNodeAt(A.getRow())->getData()->del();
		history.pop();
	}
	

	else if(A.getType() == DEL){
		//cursor = A.getRow();
		lines.getNodeAt(A.getRow())->getData()->moveCursorTo(A.getCol());
		lines.getNodeAt(A.getRow())->getData()->insert(A.getParam());
		lines.getNodeAt(A.getRow())->getData()->moveCursorTo(A.getCol());
		// Retuns a Row of that Line 
		//lines.getNodeAt()->getData()->insert(A.getParam());//MoveCursorTo()
		history.pop();
	}
	else if(A.getType() == BACKSPACE){
		//cursor = A.getRow();
		lines.getNodeAt(A.getRow())->getData()->moveCursorTo(A.getCol()-1);
		lines.getNodeAt(A.getRow())->getData()->insert(A.getParam());
		history.pop();
	}

	

		//lines.getNodeAt(cursor)->getData()->
		//insertChar(A.getParam());



	
}
}

void Editor::moveCursorUp(){
	if(cursor!=0)
		--cursor;
	
}

void Editor::moveCursorDown(){
	if(lines.getNodeAt(cursor) != lines.getTail())//
	   ++cursor;

}

void Editor::moveCursorLeft(){

	lines.getNodeAt(cursor)->getData()->moveCursorLeft();
}
void Editor::moveCursorRight(){

	lines.getNodeAt(cursor)->getData()->moveCursorRight();
}

int  Editor::getCursorCol() const {

	return lines.getNodeAt(cursor)->getData()->getCursorPosition();


}

int Editor::getCursorRow() const{
	return cursor;
}

int Editor::getLength() const {

	LinkedNode<Line>* h = lines.getHead(); ///UZunkluk 
	int i = 1;

	while(h != lines.getTail()) {
		h = h->getNext();
		i++;
	}
	//cursor++;
	return i;
}

std::string Editor::getLine(int idx) const{

	std::string str;// = "Azat";// = string(*lines.getNodeAt(idx)->getData());
	
	//const char* l = "a";//getLength () Ln
	int i = 0;
	int len = lines.getNodeAt(idx)->getData()->getLength();
	//std::cout << lines.getNodeAt(idx)->getData()->getLength()<< std::endl;
	while(i<len)//there is another chanrd in the line that cahracter 
		{
			str +=lines.getNodeAt(idx)->getData()->getCharAt(i);
		//	std::cout<< i<< lines.getNodeAt(idx)->getData()->getLength()<<"  "<<lines.getNodeAt(idx)->getData()->getCharAt(i)<< std::endl;
			i++;
		}

	return str; //*lines.getNodeAt(idx)->getData();
}
