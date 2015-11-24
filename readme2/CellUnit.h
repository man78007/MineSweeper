//---------------------------------------------------------------------------

#ifndef CellUnitH
#define CellUnitH

#include <vcl.h>
//---------------------------------------------------------------------------

/*
����� "������"
������ ������� � ������� ������
�������� ������� ����������
*/
//#include "FieldUnit.h"

class TField;

class TCell
{
  private:
   void __fastcall TCell::OnClick(TObject * Sender);
  public:
   TCell(){};
   TControl * Parent;
   TStaticText * L;
   TField * Field; //�������������� � �������� ����
   bool HasMine; //�������� �� ����
   bool Opened;  //������� ��
   bool Marked;  //�������� ��
   int NeightBoards; //���������� ������� ���
   int Row; //���������� � ����
   int Col;
   void Show();  //��������� ����� L
};

#endif