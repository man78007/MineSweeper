//---------------------------------------------------------------------------

#ifndef FieldUnitH
#define FieldUnitH
//---------------------------------------------------------------------------

#include <vcl.h>
#include "CellUnit.h"

/*
����� "���� �� ������"
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
    void GenerateMines(int HowMany); //���������� ����
    bool Finished(int HowMany); //���������, �� �������� ��
    void OnLeftClick(int x,int y); //����� ����� ������
    void OnRightClick(int x,int y); //������ ����� ������
    void DoOpen(int row,int col); //������� ����� ����
};
#endif
