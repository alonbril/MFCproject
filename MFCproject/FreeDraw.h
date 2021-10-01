#pragma once
#include "Line.h"
class FreeDraw:public Line
{
	DECLARE_SERIAL(FreeDraw)
public:
	FreeDraw();
	FreeDraw(CPoint p1, CPoint p2) :Line(p1, p2) {}

	/*FreeDraw(void);
	~FreeDraw(void);
	int getId();
	void innerDraw(CDC* dc);*/
	/*FreeDraw(CDC* dc);
	void Draw(CDC* dc) const;*/
};

