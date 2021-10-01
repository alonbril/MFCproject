#include "StdAfx.h"
#include "addShape.h"



addShape::addShape(CTypedPtrArray<CObArray, Figure*> & figuress, Figure* s): figuress(figuress), s(s)

{
}


addShape::~addShape(void)
{
}

int addShape::getMyId() { return s->getId(); }

void addShape::perform()
{
	figuress.Add(s);
}

void addShape::rollback()
{
	for (int i = 0; i < figuress.GetSize(); ++i)
		if (figuress[i] == s)
		{
			figuress.RemoveAt(i);
			return;
		}
}
