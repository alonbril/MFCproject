#pragma once
#include "stdafx.h"
class Figure: public CObject {
	//!! 21 b
	DECLARE_SERIAL(Figure)   //!!! NO ";"  
	//!! 21 e
	CPoint P1;
	CPoint P2;
	COLORREF SHAPECOLOR, fillColor;
public:
	
	int set;
	int getSet() const;
	void setSet(int);
	DWORD FigureColor;
	void SetColor(DWORD FigColor) { FigureColor = FigColor; }
	DWORD GetColor() const { return FigureColor; }
	virtual void MouseMove(CPoint, CPoint, CDC*) {}
	void setStart(CPoint p) { start = p; }
	void setSize(int sizep) { size = sizep; }
	void setEnd(CPoint p) { end = p; }
	void setBg(COLORREF c) { bgColor = c; }
	COLORREF getBg() const { return bgColor; }
	Figure() {}
	//!! 22 b
	CPoint start, end;
	int size;
	//!! 21 b
	/*Figure(CPoint p1, CPoint p2, COLORREF _SHAPRCOLOR):
		P1(p1), P2(p2)
	{}*/

	Figure::Figure(CPoint _p1, CPoint _p2)
	{
		this->P1 = _p1;
		this->P2 = _p2;
	}

	void setFillColor(COLORREF _fillColor);
	void Serialize(CArchive& ar);

	virtual int getId() { return 0; }
	virtual void Draw(CDC *dc) const
	{
		dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
		
	}
	//!! 15 b
	CPoint getP1() const 
	{ 
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	//!! 15 e
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual void Shift(int dx, int dy);
	const COLORREF getFillColor() const;
protected:

	COLORREF bgColor;
	CBrush figureBrush;
	CPen figurePen;
};
