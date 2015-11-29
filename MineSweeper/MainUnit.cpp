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

ѕредусмотрено маленькое жульничество дл€ игрока -
если он догадаетс€ "пометить/сн€ть пометку", то клетка без мины
"откроетс€".

*/
#include "FieldUnit.h"
#include "OptionsUnit.h"

TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
TField * F;

void __fastcall TMainForm::N5Click(TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N6Click(TObject *Sender)
{
 ShowMessage("Microsoft Minesweeper посв€щаетс€");        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender)
{
  OptionForm->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender)
{
 if (F) free(F);
 F = new TField(
  OptionForm->Rows,
  OptionForm->Cols,
  this
 );
 F->GenerateMines(OptionForm->HowMany);
 
}
//---------------------------------------------------------------------------

