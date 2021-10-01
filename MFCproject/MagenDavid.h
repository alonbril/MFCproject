#pragma once
#include "Figure.h"
class MagenDavid:public Figure
{
	DECLARE_SERIAL(MagenDavid)
public:
	MagenDavid() {}
	//!! 22 b
	MagenDavid(CPoint p1, CPoint p2
	);
	void Draw(CDC* dc) const;
};

