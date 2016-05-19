CPPFLAGS=-ansi -Wall -g -O0 -pedantic
SOURCE=main.cpp Editor.cpp Line.cpp Action.cpp
HEADER=LinkedList.h LinkedNode.h Line.h Editor.h Action.h

all: $(SOURCE) $(HEADER);
	g++ $(SOURCE) $(CPPFLAGS) -o hw1