#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include <unistd.h>

#include "Line.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "Editor.h"

using namespace std;

void usage()
{
	cerr << "Usage:\n\r";
	cerr << "\t./hw1 [--record \x1b[4mfilename\x1b[0m|--replay \x1b[4mfilename\x1b[0m]\n\r";
}

void print(Editor &editor)
{
	// clear screen
	cout << "\x1b[H\x1b[2J";

	int ci = editor.getCursorRow();
	int cj = editor.getCursorCol();
	int sz = editor.getLength();
	
	for (int i = 0; i < sz; ++i) {
		cout << editor.getLine(i);
		//new line
		cout << "\n\r";
	}

	// move cursor to [ci;cj]
	cout << "\x1b[" << ci+1 << ";" << cj+1 << "H";	
}

int parse(Editor &edi, ostream &out, istream &in)
{
	char c;
	in.get(c);
	out << c;
	switch (c) {
		case -1:	// EOF
		case 3:		// CTRL + C
			return 0;
		case 26: 	// CTRL + Z
			edi.undo();
			break;
		case 13:	// ENTER
			edi.insertLine();
			//cout << curr;
			break;
		case 127:	// BACKSPACE
			edi.backspace();
			break;
		case '\x1b':		
			in.get(c);
			out << c;
			in.get(c);
			out << c;
			switch (c) {
				case 51: 	// DEL
					edi.del();
					in.get(c);
					out << c;
					break;
				case 65:	// UP ARROW
					edi.moveCursorUp();
					break;
				case 66:	// DOWN ARROW
					edi.moveCursorDown();					
					break;
				case 67:	// RIGHT ARROW
					edi.moveCursorRight();					
					break;
				case 68:	// LEFT ARROW
					edi.moveCursorLeft();					
					break;
			}
			break;
		default:
			edi.insertChar(c);
	}
	
	return 1;
}

void loop(ostream &out, istream &in, float sleep_sec) 
{
	cout << "\x1b[?1049h" << endl << endl;

	Editor edi;
	while (true) {
		print(edi);

		if (!parse(edi, out, in))
			break;
			
		usleep(sleep_sec * 1e6);
	}
	
	cout << "\x1b[?1049l";
}

int main(int argc, char *argv[]) 
{		
	system("stty raw < /dev/tty"); 
	system("stty -echo < /dev/tty");
	setbuf(stdout, NULL);			
		
	if (argc == 1) {
		loop(cout, cin, 0);		
	} else if (argc == 3) {
		if (strcmp(argv[1], "--record") == 0) {	
			ofstream file(argv[2]);		
			if (file.is_open()) {
				loop(file, cin, 0);	
				file.close();
			} else {
				cerr << "Output file " << string(argv[2]) << " could not be opened.\n\r";
			}
		} else if (strcmp(argv[1], "--replay") == 0) {
			ifstream in(argv[2]);
			if (in.is_open()) {
				loop(cout, in, 0.5);	
				in.close();
			} else {
				cerr << "Input file " << string(argv[2]) << " could not be opened.\n\r";
			}
		} else {
			cerr << "Second argument should be either '--record' or '--replay'. However, '" << string(argv[1]) <<"' is found.\n\r";
		}
	} else {
		usage();
	}
	
	system("stty cooked < /dev/tty"); 
	system("stty echo < /dev/tty");	
}


