//---------------------------------------------------------------------------

#ifndef CellUnitH
#define CellUnitH

#include <vcl.h>
//---------------------------------------------------------------------------

/*
Класс "Клетка"
Помимо свойств и методов предка
содержит игровую информацию
*/
//#include "FieldUnit.h"

class TField;

class TCell
{
  private:
   void __fastcall TCell::OnClick(TObject * Sender);
   void __fastcall TCell::OnContextPopup(TObject *Sender, const TPoint &MousePos, bool &Handled);

  public:
   TCell(){};
   TControl * Parent;
   TStaticText * L;
   TField * Field; //Принадлежность к игровому полю
   bool HasMine; //Содержит ли мину
   bool Opened;  //Открыта ли
   bool Marked;  //Помечена ли
   int NeightBoards; //Количество сосених мин
   int Row; //Координаты в поле
   int Col;
   void Show();  //Настроить показ L
};

#endif
