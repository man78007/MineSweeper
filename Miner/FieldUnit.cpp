//---------------------------------------------------------------------------


#pragma hdrstop

//---------------------------------------------------------------------------
#include "FieldUnit.h"

void TField::InitCells()
//Установить начальное значение каждой клетки
{
  const int Size = 20;
  const int Left = 10;
  const int Top = 10;
 //Создать матрицу Cells
  Cells = new TCell *[Rows]; //Строки
  for (int i=0; i<Rows; i++) Cells[i] = new TCell[Cols]; //Элементы строк

  //Заполнить свойства каждой ячейки
  for (int r=0; r<Rows; r++)
   for (int c=0; c<Cols; c++)
    {
      Cells[r][c].Parent = this->Parent;
      Cells[r][c].Field = this;
      //Для игры
      Cells[r][c].HasMine = false;
      Cells[r][c].Opened = false;
      Cells[r][c].Marked = false;
      Cells[r][c].NeightBoards = 0;
      Cells[r][c].Row = r;
      Cells[r][c].Col = c;
      //Для отображения
      Cells[r][c].L = new TStaticText(Parent);
      Cells[r][c].L->AutoSize = false;
      Cells[r][c].L->Parent = (TWinControl*)Parent;
      Cells[r][c].L->Width = Size;
      Cells[r][c].L->Height = Size;
      Cells[r][c].L->Left = Size * c + Left;
      Cells[r][c].L->Top = Size * r + Top;
      Cells[r][c].L->BorderStyle = sbsSunken;
      //Нарисовать
      Cells[r][c].Show();
    }
}


#pragma package(smart_init)
