//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
/*
ѕроект состоит из следующих модулей:
Main - главна€ форма
Field - игровое поле
Cell - одна €чейка игрового пол€
Options - настройки

Cell экспортирует класс, содержит TLabel,
с дополнительными характеристиками
"ќткрыта"/"«акрыта"/"ѕомечена"/ оличество соседей/≈сть ли мина
обеспечивает передачу в Field событи€ "MouseClick"
"ѕравый Click" обрабатывает самосто€тельно

Field содержит матрицу произвольного размера из Cell
ќбрабатывает "Ћевый" Click, открыва€ текущую клетку
и некоторых соседей

Options позвол€ет задавать размеры пол€
и раскраску клеток




*/
#include "FieldUnit.h"

TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
TField * F;

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  F = new TField(10,10,this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button2Click(TObject *Sender)
{
 for (int r=0; r<F->Rows; r++)
  for (int c=0; c<F->Cols; c++)
  {
   F->Cells[r][c].Marked = !F->Cells[r][c].Marked;
   F->Cells[r][c].Show();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button3Click(TObject *Sender)
{
 for (int r=0; r<F->Rows; r++)
  for (int c=0; c<F->Cols; c++)
  {
   F->Cells[r][c].Opened = !F->Cells[r][c].Opened;
   F->Cells[r][c].NeightBoards = rand() %9;
   F->Cells[r][c].Show();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button4Click(TObject *Sender)
{
 for (int r=0; r<F->Rows; r++)
  for (int c=0; c<F->Cols; c++)
  {
   F->Cells[r][c].HasMine = !F->Cells[r][c].HasMine;
   F->Cells[r][c].Opened = F->Cells[r][c].HasMine;
   F->Cells[r][c].Show();
  }
}
//---------------------------------------------------------------------------

