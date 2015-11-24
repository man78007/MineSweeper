//---------------------------------------------------------------------------


#pragma hdrstop

//---------------------------------------------------------------------------
#include "FieldUnit.h"

void TField::InitCells()
//Установить начальное значение каждой клетки
{
  const int Size = 20;
  const int Left = 10;
  const int Top = 10;
 //Создать матрицу Cells
  Cells = new TCell *[Rows]; //Строки
  for (int i=0; i<Rows; i++) Cells[i] = new TCell[Cols]; //Элементы строк

  //Заполнить свойства каждой ячейки
  for (int r=0; r<Rows; r++)
   for (int c=0; c<Cols; c++)
    {
      Cells[r][c].Parent = this->Parent;
      Cells[r][c].Field = this;
      //Для игры
      Cells[r][c].HasMine = false;
      Cells[r][c].Opened = false;
      Cells[r][c].Marked = false;
      Cells[r][c].NeightBoards = 0;
      Cells[r][c].Row = r;
      Cells[r][c].Col = c;
      //Для отображения
      Cells[r][c].L = new TStaticText(Parent);
      Cells[r][c].L->AutoSize = false;
      Cells[r][c].L->Parent = (TWinControl*)Parent;
      Cells[r][c].L->Width = Size;
      Cells[r][c].L->Height = Size;
      Cells[r][c].L->Left = Size * c + Left;
      Cells[r][c].L->Top = Size * r + Top;
      Cells[r][c].L->BorderStyle = sbsSunken;
      //Нарисовать
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
        //Проверка на успешное окончание.
        //Окончено - это когда каждая клетка
        //либо открыта, либо закрыта и помечена.
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

    void TField::OnClick(int r,int c)
    {
     //Если нажали на кнопку
     ShowMessage(IntToStr(r)+" "+IntToStr(c));
    }


#pragma package(smart_init)
