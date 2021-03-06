#include "stdafx.h"
#include "UndoRedo.h"

UNDOREDO::UNDOREDO() {};
UNDOREDO::~UNDOREDO() {};
Figure* UNDOREDO::redoPop()
{
	Figure* fig = NULL;
	fig = redoStack.top();
	redoStack.pop();
	undoStack.push(fig);
	return fig;
}


void UNDOREDO::pushRedo(Figure* Figuress)
{
	redoStack.push(Figuress);
}

Figure* UNDOREDO::undoPop(bool pushRedo)
{
	Figure* fig = NULL;
	fig = undoStack.top();
	undoStack.pop();
	if (pushRedo == true)
		redoStack.push(fig);
	return fig;
}


void UNDOREDO::pushUndo(Figure* Figuress)
{
	undoStack.push(Figuress);
}

void UNDOREDO::clearRedo()
{
	Figure* figure = NULL;
	while (!redoStack.empty())
	{
		figure = redoStack.top();
		redoStack.pop();
		if (figure != NULL)
			delete figure;
	}
}
void UNDOREDO::clearUndo()
{
	Figure* figure = NULL;
	while (!undoStack.empty())
	{
		figure = undoStack.top();
		undoStack.pop();
	}
}

int UNDOREDO::redoSize() const
{
	return redoStack.size();
}

int UNDOREDO::undoSize() const
{
	return undoStack.size();
}
