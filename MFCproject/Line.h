#pragma once
#include "Figure.h"
class Line: public Figure
{
	DECLARE_SERIAL(Line)

public:
	Line(){}
	Line(CPoint p1,CPoint p2);
	void Draw(CDC* dc) const;

};

