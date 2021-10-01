#include "stdafx.h"
#include "Line.h"


IMPLEMENT_SERIAL(Line, CObject, 1)


Line::Line(CPoint p1,CPoint p2) :Figure(p1, p2)
{
	
}
void Line::Draw(CDC* dc) const
{

	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->MoveTo(p1.x, p1.y);
	dc->LineTo(p2.x, p2.y);
}
