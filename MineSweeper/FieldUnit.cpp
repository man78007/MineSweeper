//---------------------------------------------------------------------------


#pragma hdrstop

//---------------------------------------------------------------------------
#include "FieldUnit.h"

void TField::InitCells()
//���������� ��������� �������� ������ ������
{
  const int Size = 20;
  const int Left = 10;
  const int Top = 10;
 //������� ������� Cells
  Cells = new TCell *[Rows]; //������
  for (int i=0; i<Rows; i++) Cells[i] = new TCell[Cols]; //�������� �����

  //��������� �������� ������ ������
  for (int r=0; r<Rows; r++)
   for (int c=0; c<Cols; c++)
    {
      Cells[r][c].Parent = this->Parent;
      Cells[r][c].Field = this;
      //��� ����
      Cells[r][c].HasMine = false;
      Cells[r][c].Opened = false;
      Cells[r][c].Marked = false;
      Cells[r][c].NeightBoards = 0;
      Cells[r][c].Row = r;
      Cells[r][c].Col = c;
      //��� �����������
      Cells[r][c].L = new TStaticText(Parent);
      Cells[r][c].L->AutoSize = false;
      Cells[r][c].L->Parent = (TWinControl*)Parent;
      Cells[r][c].L->Width = Size;
      Cells[r][c].L->Height = Size;
      Cells[r][c].L->Left = Size * c + Left;
      Cells[r][c].L->Top = Size * r + Top;
      Cells[r][c].L->BorderStyle = sbsSunken;
      //����������
      Cells[r][c].Show();
    }
}

    int TField::check(int r,int c)
      {
       if (r<0) return 0;
       if (c<0) return 0;
       if (r>=Rows) return 0;
       if (c>=Cols) return 0;
       if (Cells[r][c].HasMine) return 1;
       return 0;
      }

    void TField::GenerateMines(int HowMany)
    {
          for (int row=0; row<Rows;row++)
           for (int col=0; col<Rows;col++)
           {
            Cells[row][col].HasMine = false;
            Cells[row][col].Opened = false;
            Cells[row][col].Show();
            Cells[row][col].NeightBoards = 0;
            Cells[row][col].Marked = false;
           };

          int index = HowMany;
          while (index) {
           int row = random(Rows);
           int col = random(Cols);
           if (Cells[row][col].HasMine) continue;
           Cells[row][col].HasMine = true;
           index--;
          }

          for (int row=0; row<Rows;row++)
           for (int col=0; col<Rows;col++)
            {
              Cells[row][col].NeightBoards+=check(row-1,col-1);
              Cells[row][col].NeightBoards+=check(row-1,col-0);
              Cells[row][col].NeightBoards+=check(row-1,col+1);
              Cells[row][col].NeightBoards+=check(row-0,col-1);
              Cells[row][col].NeightBoards+=check(row-0,col+1);
              Cells[row][col].NeightBoards+=check(row+1,col-1);
              Cells[row][col].NeightBoards+=check(row+1,col-0);
              Cells[row][col].NeightBoards+=check(row+1,col+1);
            }

          for (int row=0; row<Rows;row++)
           for (int col=0; col<Rows;col++)
            Cells[row][col].Show();
    }


        bool TField::Finished(int HowMany)
        //�������� �� �������� ���������.
        //�������� - ��� ����� ������ ������
        //���� �������, ���� ������� � ��������.
        {
            int Marked = 0;
            int OK = 0;
            for (int row=0; row<Rows; row++)
             for (int col=0; col<Cols; col++)
             {
               if (Cells[row][col].Marked)
               {
                Marked++;
                if (Cells[row][col].HasMine) OK++;
               }
             };
             if (Marked != HowMany) return false;
             return (OK == HowMany);
        }

    void TField::OnRightClick(int r,int c)
    {
     //���� ������ �� ������ ������ - �������� �������
     // ShowMessage("R="+IntToStr(r)+" "+IntToStr(c));
      if (Cells[r][c].Opened) return; //�������� ��������?
      Cells[r][c].Marked = !Cells[r][c].Marked;
      Cells[r][c].Show();
    }

    void TField::OnLeftClick(int r,int c)
    {
     //���� ������ �� ����� ������
     //ShowMessage("L="+IntToStr(r)+" "+IntToStr(c));

  //���� ������ ����� ������, �� �������� (� ���� �������) Opened
  //� ��������� �� ����������� �����
      if (Cells[r][c].HasMine) {
        ShowMessage("���� ��������� ������ ���� ���!");
        ShowMessage("Formatting C:");
        ShowMessage("Formatting D:");
        ShowMessage("Formatting E:");
        return;
      };
  //������� ������� - ����������
      DoOpen(r,c);
      Cells[r][c].Opened = true;
      Cells[r][c].Show();
    }


    void TField::DoOpen(int row,int col)
    //������� ��� �������� ���� ��� ���.
    //���������, ��������!
    {
    //�������� ��������� - �� �������� ����
     if (row<0) return;
     if (col<0) return;
     if (row>=Rows) return;
     if (col>=Cols) return;
    //�������� ���������
     Cells[row][col].Show();
     if (Cells[row][col].HasMine) return; //- ��� ����
     if (Cells[row][col].Opened) return; //-��� �������
     if (Cells[row][col].NeightBoards>0) return; //������� ���������. ��������� ������ 0
    //�� ������. �����������.
      Cells[row][col].Opened = true; //���������
      Cells[row][col].Show(); //������
    //�, �������, ��������: ���� �������
      for (int i=-1; i<=1; i++)
       for (int j=-1; j<=1; j++)
        DoOpen(row+i,col+j);
    }


#pragma package(smart_init)
