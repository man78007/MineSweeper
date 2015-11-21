//---------------------------------------------------------------------------


#pragma hdrstop

//---------------------------------------------------------------------------
#include "FieldUnit.h"

void TField::InitCells()
//���������� ��������� �������� ������ ������
{
  const int Size = 20;
  const int Left = 10;
  const int Top = 10;
 //������� ������� Cells
  Cells = new TCell *[Rows]; //������
  for (int i=0; i<Rows; i++) Cells[i] = new TCell[Cols]; //�������� �����

  //��������� �������� ������ ������
  for (int r=0; r<Rows; r++)
   for (int c=0; c<Cols; c++)
    {
      Cells[r][c].Parent = this->Parent;
      Cells[r][c].Field = this;
      //��� ����
      Cells[r][c].HasMine = false;
      Cells[r][c].Opened = false;
      Cells[r][c].Marked = false;
      Cells[r][c].NeightBoards = 0;
      Cells[r][c].Row = r;
      Cells[r][c].Col = c;
      //��� �����������
      Cells[r][c].L = new TStaticText(Parent);
      Cells[r][c].L->AutoSize = false;
      Cells[r][c].L->Parent = (TWinControl*)Parent;
      Cells[r][c].L->Width = Size;
      Cells[r][c].L->Height = Size;
      Cells[r][c].L->Left = Size * c + Left;
      Cells[r][c].L->Top = Size * r + Top;
      Cells[r][c].L->BorderStyle = sbsSunken;
      //����������
      Cells[r][c].Show();
    }
}


#pragma package(smart_init)
