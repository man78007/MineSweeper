//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OptionsUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionForm *OptionForm;
//---------------------------------------------------------------------------
__fastcall TOptionForm::TOptionForm(TComponent* Owner)
        : TForm(Owner)
{
        HowMany = 20;
        Rows = 10;
        Cols = 10;
        Size = 20;
        OpenedColor = (TColor)RGB(100,255,100);
        MarkedColor = (TColor)RGB(255,255,50);
        NormalColor = clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TOptionForm::FormShow(TObject *Sender)
{
    edMines->Text = IntToStr(HowMany);
    edRows->Text = IntToStr(Rows);
    edCols->Text = IntToStr(Cols);
    edSize->Text = IntToStr(Size);
    ColorBoxMarked->Selected = MarkedColor;
    ColorBoxNormal->Selected = NormalColor;
    ColorBoxOpened->Selected = OpenedColor;
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::edMinesChange(TObject *Sender)
{
 try
 {
  HowMany = StrToInt(edMines->Text);
 }
 catch  (...)
 {};
 if (HowMany > Rows*Cols-1) {
  HowMany = Rows*Cols-1;
  ShowMessage("Столько не поместится");
 }

  if (HowMany > Rows*Cols/2) {
  ShowMessage("Однако!");
 }

}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::edRowsChange(TObject *Sender)
{
 try
 {
  Rows = StrToInt(edRows->Text);
 }
 catch  (...)
 {};
 if (Rows<3) Rows = 3;
 if (Rows>20) ShowMessage("Странный выбор");
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::edColsChange(TObject *Sender)
{
 try
 {
  Cols = StrToInt(edCols->Text);
 }
 catch  (...)
 {};
 if (Cols<3) Cols = 3;
 if (Cols>20) ShowMessage("Странный выбор");
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::ColorBoxNormalChange(TObject *Sender)
{
  NormalColor = ColorBoxNormal->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::ColorBoxOpenedChange(TObject *Sender)
{
  OpenedColor = ColorBoxOpened->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::ColorBoxMarkedChange(TObject *Sender)
{
  MarkedColor = ColorBoxMarked->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TOptionForm::edSizeChange(TObject *Sender)
{
 try
 {
  Size = StrToInt(edSize->Text);
 }
 catch  (...)
 {};
 if (Size<10) Size = 10;
 if (Size>100) ShowMessage("Странный выбор");
}
//---------------------------------------------------------------------------

