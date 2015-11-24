//---------------------------------------------------------------------------

#ifndef FieldUnitH
#define FieldUnitH
//---------------------------------------------------------------------------

#include <vcl.h>
#include "CellUnit.h"

/*
Класс "Поле из клеток"
*/

class TField{
 private:
    void InitCells();
    int check(int r,int c);

    TControl * Parent;
 public:
    int Rows;
    int Cols;
    TCell * * Cells;
    TField(int Rows,int Cols, TControl * Parent){
     this->Rows = Rows;
     this->Cols = Cols;
     this->Parent = Parent;
     InitCells();
    };
    void GenerateMines(int HowMany);
    bool Finished(int HowMany);
    void OnClick(int x,int y);
};
#endif
