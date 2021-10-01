
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	/*ON_BN_CLICKED(IDC_BUTTON6, &CMFCprojectDlg::OnBnClickedButton6)*/
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//!! 16 b
	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
	//!! 16 e

	return TRUE;  // return TRUE  unless you set the focus to a control
}
BOOL CMFCprojectDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}

	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();
		
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
bool isrefill;
void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	curColor = ShapeColorFill.GetColor();
	start = point;
	isPressed = true;
    //!! 20 b
	//figs.Add(new Figure(start, start));
	switch (futureFigureKind)
	{
	case 1:
		figs.Add(new RectangleF(start, start));
		break;
	case 2:
  	    figs.Add(new EllipseF(start, start));
		break;
	case 3:
		figs.Add(new MagenDavid(start, start));
		break;
	case 4:
		figs.Add(new Line(start,start));
		break;
	case 5:
		break;
	case 6:
		BOOL ExtFloodFill(
			int x,
			int y,
			COLORREF crColor,
			UINT nFillType);
		break;
		

	}
	
	actions.push_back(ADD);
	undo_redo_objects.clearRedo();
	//!! 20 e
	UpdateWindow();
	Invalidate();
	CDialog::OnLButtonUp(nFlags, point);
	UpdateWindow();
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
		
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
		CClientDC dc(this);
		CPen* oldPen;
		CBrush myBrush2, * oldBrush;
		myBrush2.CreateSolidBrush(curColor);
		oldBrush = dc.SelectObject(&myBrush2);
		CPen myPen1(PS_SOLID, 2, RGB(0, 0, 0));
		oldPen = dc.SelectObject(&myPen1);



		if (futureFigureKind == 5)
		{
			dc.MoveTo(start);
			dc.LineTo(end.x, end.y);
			end = point;
			dc.MoveTo(start);
			dc.LineTo(end.x, end.y);
			figs.Add(new FreeDraw(start, end));
			start = end;
		}
		int inshape = 1;
		int i = 0;
		int l=i;
		if (inshape == 1)
		{

			CBrush myBrush3;
			myBrush3.CreateSolidBrush(figs[l]->GetColor());
			oldBrush = dc.SelectObject(&myBrush3);
			UpdateWindow();
			figs[l]->MouseMove(start, end, &dc);
			end = point;
		}
		
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCprojectDlg::OnBnClickedRadio1()
{
	futureFigureKind = 1;
}


void CMFCprojectDlg::OnBnClickedRadio2()
{

	futureFigureKind = 2;
}
void CMFCprojectDlg::OnBnClickedRadio3()
{
	futureFigureKind = 3;
}

void CMFCprojectDlg::OnBnClickedRadio4()
{
	futureFigureKind = 4;

}
void CMFCprojectDlg::OnBnClickedRadio5()
{
	futureFigureKind = 5;
}





void CMFCprojectDlg::OnBnClickedButton1()
{
	CFile file;
	CFileDialog FileDlg(TRUE);
	FileDlg.m_ofn.lpstrFilter = _T("DATA Files (*.dat)\0*.dat\0");
	FileDlg.m_ofn.lpstrTitle = _T("Save DATA File As");
	CString filename;
	if (FileDlg.DoModal() == IDOK)
	{
		filename = FileDlg.GetPathName();
		filename.Append(_T(".dat"));
	}
	if (file.Open(filename, CFile::modeCreate | CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
	}
	else
		return;
	file.Close();
}


void CMFCprojectDlg::OnBnClickedButton2()
{

			     // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}

void CMFCprojectDlg::OnBnClickedButton3()// NEW File
{
	
	figs.RemoveAll();
	undo_redo_objects.clearRedo();
	undo_redo_objects.clearUndo();
	Invalidate();
}


void CMFCprojectDlg::OnBnClickedButton4() //Redo
{
	bool revival = false;
	if (actions.size() == 0)
		return;
	// if last action was removing an object or on a series of redoing objects
	if (actions[actions.size() - 1] == UNDO_OBJECT || actions[actions.size() - 1] == REDO_OBJECT)
	{
		if (undo_redo_objects.redoSize() > 0)
		{
			actions.pop_back();
			figs.Add(undo_redo_objects.redoPop());
			actions.push_back(REDO_OBJECT);
			Invalidate();
		}
	}

	else if (actions[actions.size() - 1] == REVIVE_OBJECT || actions[actions.size() - 1] == REMOVE_REVIVAL)
	{
		if (figs.GetSize() > 0)
		{
			for (int i = actions.size() - 1; i >= 0; i--)
			{
				if (actions[i] == REVIVE_OBJECT)
				{
					revival = true;
					actions.erase(actions.end() - (actions.size() - i));
					actions.push_back(REMOVE_REVIVAL);
					break;
				}
			}

			if (revival)
			{
				undo_redo_objects.pushUndo(figs[figs.GetSize() - 1]);
				figs.RemoveAt(figs.GetSize() - 1);
				Invalidate();
			}
		}
	}
}



void CMFCprojectDlg::OnBnClickedButton5() // UNDO
{
	// if last action was adding an object or on a series of undoing objects
	if (actions.size() == 0)
		return;
	if (actions[actions.size() - 1] == ADD || actions[actions.size() - 1] == REDO_OBJECT)
	{
		if (figs.GetSize() > 0)
		{
			actions.pop_back();
			undo_redo_objects.pushRedo(figs[figs.GetSize() - 1]);
			figs.RemoveAt(figs.GetSize() - 1);
			actions.push_back(UNDO_OBJECT);
			Invalidate();
		}
	}
	else if (actions[actions.size() - 1] == UNDO_OBJECT)
	{
		if (figs.GetSize() > 0)
		{
			// check if the figure is from the last set of objects defined, otherwise don't delete it
			if (figs[figs.GetSize() - 1]->getSet() == set)
			{
				actions.pop_back();
				undo_redo_objects.pushRedo(figs[figs.GetSize() - 1]);
				figs.RemoveAt(figs.GetSize() - 1);
				actions.push_back(UNDO_OBJECT);
				Invalidate();
			}
		}
	}
	else if (actions[actions.size() - 1] == REMOVE || actions[actions.size() - 1] == REMOVE_REVIVAL || actions[actions.size() - 1] == REVIVE_OBJECT)
	{
		if (undo_redo_objects.undoSize() > 0)
		{

			for (int i = actions.size() - 1; i >= 0; i--)
			{
				if (actions[i] == REMOVE || actions[i] == REMOVE_REVIVAL)
				{
					actions.erase(actions.end() - (actions.size() - i));
					break;
				}
			}

			figs.Add(undo_redo_objects.undoPop(false));
			actions.push_back(REVIVE_OBJECT);
			Invalidate();
		}
	}
}



void CMFCprojectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	curColor = dc.GetPixel(point);
	Invalidate(0);
	CDialog::OnRButtonDown(nFlags, point);
}

//void CMFCprojectDlg::OnBnClickedMfccolorbutton1()
//{
//	
//}





//void CMFCprojectDlg::OnBnClickedButton6()
//{
//	futureFigureKind = 6;
//	
//	HCURSOR hcur;
//	hcur = AfxGetApp()->LoadCursorW(MAKEINTRESOURCE(IDC_AFXBARRES_FILL));
//	SetClassLong(m_hWnd, GCLP_HCURSOR, (LONG)hcur);
//	CColorDialog dlg;
//	if (dlg.DoModal() == IDOK)
//	{
//		curColor = dlg.GetColor();
//		
//	}
//
//}
