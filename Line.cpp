#include "Line.h"
	
Line::Line()
{
	size = 80;
	buffer = (char *)malloc(size * sizeof(char));
	gapstart = 0;
	gapend = size;
}

void Line::insert(char c)
{
	if (gapstart < gapend) {
		buffer[gapstart++] = c;
	}
	
	if (gapstart == gapend) {
		size *= 2;
		buffer = (char *)realloc(buffer, size * sizeof(char));
		for (int i = size/2-1, j = size-1; i >= gapend; --i, --j) {
			buffer[j] = buffer[i];
		}
		gapend += size/2;
	}
}

void Line::del()
{
	if (gapend < size)
		++gapend;
}

void Line::backspace()
{
	if (gapstart > 0)
		--gapstart;
}
	
int Line::getCursorPosition() const
{
	return gapstart;
}

int Line::getLength() const
{
	return gapstart + (size - gapend);
}

char Line::getCharAt(int idx) const
{
	if (idx >= gapstart)
		idx += gapend - gapstart;
	
	return buffer[idx];
}

void Line::moveCursorLeft()
{
	if (gapstart > 0) {
		buffer[--gapend] = buffer[--gapstart];
	}
}

void Line::moveCursorRight()
{
	if (gapend < size) {
		buffer[gapstart++] = buffer[gapend++];
	}		
}

void Line::moveCursorTo(int idx)
{
	if (idx < 0)
		idx = 0;
	if (idx > getLength())
		idx = getLength();
		
	while (idx > gapstart) {
		moveCursorRight();
	}
	
	while (idx < gapstart) {
		moveCursorLeft();
	}		
}
