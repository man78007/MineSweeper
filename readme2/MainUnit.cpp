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

void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
  F->GenerateMines(StrToInt(LabeledEdit1->Text));
}
//---------------------------------------------------------------------------

bool Fin=false;

void __fastcall TMainForm::BitBtn2Click(TObject *Sender)
{
   for (int r=0; r<F->Rows; r++)
    for (int c=0; c<F->Cols; c++)
     {
      F->Cells[r][c].Marked = F->Cells[r][c].HasMine && Fin;
      F->Cells[r][c].Opened = !F->Cells[r][c].Marked;
      F->Cells[r][c].Show();
     }
   Fin = !Fin;
   if (F->Finished(StrToInt(LabeledEdit1->Text)))
    ShowMessage("��������");
   else
    ShowMessage("�� ��������");

}
//---------------------------------------------------------------------------

