//---------------------------------------------------------------------------


#pragma hdrstop

#include "CellUnit.h"
#include "FieldUnit.h"

//---------------------------------------------------------------------------


#pragma package(smart_init)
   void __fastcall TCell::OnClick(TObject * Sender)
   {
    //ShowMessage("Click to "+IntToStr(Row)+":"+IntToStr(Col));
     Field->OnLeftClick(Row,Col); //Вызвать метод контейнера, передав ему свои координаты
   }

   void __fastcall TCell::OnContextPopup(TObject *Sender, const TPoint &MousePos, bool &Handled)
   {
     Field->OnRightClick(Row,Col); //Вызвать метод контейнера, передав ему свои координаты
   }

   void TCell::Show()  //Настроить показ L
   {
     if (L->OnClick == NULL) L->OnClick = this->OnClick;
     if (L->OnContextPopup == NULL) L->OnContextPopup = this->OnContextPopup;

     if (Opened)
       {
        if (HasMine)
         {
           L->Color = clRed;
           L->Caption = "O";
         }
        else
         {
          L->Color = (TColor)RGB(150,150,255);
          if (NeightBoards)     L->Caption = IntToStr(NeightBoards);
          else                  L->Caption = "";
         }
        return;
       }
 //Если поле закрыто, то красить в
  //серый цвет, если не помечено
  //желтый, если помечено пользователем
  if (Marked)
  {
   L->Color = clYellow;
   L->Caption = "";
   return;
  }
  else
   L->Color = clBtnFace;

  //И, наконец, если есть хоть один ОТКРЫТЫЙ сосед, то вывести количество соседних мин
  //цветом, ему соответствующим, ниаче - не выводить ничего

      bool IsOpened = false;
      for (int r=-1; r<=1; r++) for (int c=-1; c<=1; c++) {
        if ((r==0) && (c==0)) continue; //Себя не проверять
        if (r+Row<0) continue;
        if (c+Col<0) continue;
        if (r+Row>=Field->Rows) continue;
        if (c+Col>=Field->Cols) continue;
        //Есть такая клеточка.
        if (Field->Cells[r+Row][c+Col].Opened) {IsOpened=true; break;};
      };
      if (IsOpened) {
       L->Caption = IntToStr(NeightBoards);
      } else L->Caption = "";
      L->Visible = true;
   }

