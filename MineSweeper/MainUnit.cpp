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

