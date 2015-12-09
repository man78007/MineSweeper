//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
/*
������ ������� �� ��������� �������:
Main - ������� �����
Field - ������� ����
Cell - ���� ������ �������� ����
Options - ���������

Cell ������������ �����, �������� TLabel,
� ��������������� ����������������
"�������"/"�������"/"��������"/���������� �������/���� �� ����
������������ �������� � Field ������� "MouseClick"
"������ Click" ������������ ��������������

Field �������� ������� ������������� ������� �� Cell
������������ "�����" Click, �������� ������� ������
� ��������� �������

Options ��������� �������� ������� ����
� ��������� ������

������������� ��������� ������������ ��� ������ -
���� �� ���������� "��������/����� �������", �� ������ ��� ����
"���������".

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
 ShowMessage("Microsoft Minesweeper �����������");        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender)
{
  OptionForm->ShowModal();        
}
//---------------------------------------------------------------------------

int OldRows=0;
int OldCols=0;

void __fastcall TMainForm::N3Click(TObject *Sender)
{
 bool NeedToCreate = F == NULL;
 if (F)
 {
  if
  (
    (OldRows !=OptionForm->Rows)
    ||
    (OldCols != OptionForm->Cols)
  )
  {
   F->Free();
   free(F);
   F = NULL;
   NeedToCreate = true;
  };
  }

  if (NeedToCreate)
  {
   OldRows =OptionForm->Rows;
   OldCols = OptionForm->Cols;
   F = new TField(
    OldRows,
    OldCols,
    this
    );

 };




 F->GenerateMines(OptionForm->HowMany);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
  Timer1->Enabled = false;
  for (int r=0; r<F->Rows; r++)
   for (int c=0; c<F->Cols; c++)
   {
     F->Cells[r][c].Opened = true;
     F->Cells[r][c].Show();
   }
}
//---------------------------------------------------------------------------

