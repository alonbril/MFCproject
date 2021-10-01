
// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"
//!! 17 b
#include "RectangleF.h"
#include "EllipseF.h"
#include "MagenDavid.h"
#include "Line.h"
#include "FreeDraw.h"
#include "Command.h"
#include <stack>
#include <vector>
#include "UndoRedo.h"
#include "stackM.h"

//!! 17 e

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	enum MODE { Paint };
	enum Actions { ADD, REMOVE, REVIVE_OBJECT, UNDO_OBJECT, REDO_OBJECT, CHANGE_COLOR, REMOVE_REVIVAL };
	int set; 
	CPoint start, end;
	CButton RedoB, undoB, unClearB;
	bool isPressed=false;
	COLORREF curColor;
	//UndoRedo<Figure*> UR;
	UNDOREDO undo_redo_objects;
	Figure* figtemp;
	vector<Actions> actions;
	
	 CTypedPtrArray< CObArray, Figure*> figs;
     //!! 17 b
	 int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	 int choooseJoke = 1;
	 //!! 17 e
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	BOOL OnEraseBkgnd(CDC* pDC);
	bool m_mouseDraging{ false };
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton4();
	
private:
	class std::stack<Command*> commands, undoes; // commands = stack of undo. undoes = stack of redo. temp = stack of clearAll.
	CTypedPtrArray<CObArray, Figure*> Figuress;
public:
	afx_msg void OnBnClickedButton5();
	void OnRButtonDown(UINT nFlags, CPoint point);
	/*afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedButton6();*/
	// variable of change color button
	CMFCColorButton ShapeColorFill;
	};
