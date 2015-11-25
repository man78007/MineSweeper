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
    void GenerateMines(int HowMany); //Расставить мины
    bool Finished(int HowMany); //Проверить, не окончено ли
    void OnLeftClick(int x,int y); //Левая мышка нажата
    void OnRightClick(int x,int y); //Правая мышка нажата
    void DoOpen(int row,int col); //Открыть часть поля
};
#endif
