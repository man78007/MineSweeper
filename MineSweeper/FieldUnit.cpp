//---------------------------------------------------------------------------


#pragma hdrstop

//---------------------------------------------------------------------------
#include "FieldUnit.h"
#include "OptionsUnit.h"
#include "MainUnit.h"

void TField::InitCells()
//Установить начальное значение каждой клетки
{
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
      Cells[r][c].L->Width = OptionForm->Size;
      Cells[r][c].L->Height = OptionForm->Size;
      Cells[r][c].L->Left = OptionForm->Size * c + Left;
      Cells[r][c].L->Top = OptionForm->Size * r + Top;
      Cells[r][c].L->BorderStyle = sbsSunken;
      //Нарисовать
      //Cells[r][c].Show();
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
           for (int col=0; col<Cols;col++)
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
           for (int col=0; col<Cols;col++)
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
           for (int col=0; col<Cols;col++)
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

     void TField::Open()
     {
       MainForm->Timer1->Enabled = true;
     }

    void TField::OnRightClick(int r,int c)
    {
     //Если нажали на правую кнопку - изменить пометку
     // ShowMessage("R="+IntToStr(r)+" "+IntToStr(c));
      if (Cells[r][c].Opened) return; //Помечать открытое?
      Cells[r][c].Marked = !Cells[r][c].Marked;
      Cells[r][c].Show();
      if (Finished(OptionForm->HowMany))
      {
       ShowMessage("ПОБЕДА!!!");
       Open();
      }
    }

    void TField::OnLeftClick(int r,int c)
    {
     //Если нажали на левую кнопку
     //ShowMessage("L="+IntToStr(r)+" "+IntToStr(c));

  //Если нажата левая кнопка, то изменить (в одну сторону) Opened
  //И проверить на НЕОЖИДАННЫЙ БАБАХ
      if (Cells[r][c].HasMine) {
        ShowMessage("Сапёр ошибается только один раз!");
        Open();
        return;
      };
  //Открыть соседей - рекурсивно
      DoOpen(r,c);
      Cells[r][c].Opened = true;
      Cells[r][c].Show();

      if (Finished(OptionForm->HowMany)) ShowMessage("ПОБЕДА!!!");
    }


    void TField::DoOpen(int row,int col)
    //Открыть все соседние поля без мин.
    //Осторожно, рекурсия!
    {
    //Проверки окончания - за границей поля
     if (row<0) return;
     if (col<0) return;
     if (row>=Rows) return;
     if (col>=Cols) return;
    //Проверка окончания
     Cells[row][col].Show();
     if (Cells[row][col].HasMine) return; //- там мина
     if (Cells[row][col].Opened) return; //-уже открыто
     if (Cells[row][col].NeightBoards>0) return; //Соседей многовато. Открываем только 0
    //Всё хорошо. Открываемся.
      Cells[row][col].Opened = true; //Фиксируем
      Cells[row][col].Marked = false; //Так не бывает потому сто
      Cells[row][col].Show(); //Рисуем
    //И, наконец, рекурсия: всех соседей
      for (int i=-1; i<=1; i++)
       for (int j=-1; j<=1; j++)
        DoOpen(row+i,col+j);
    }

    void TField::Free() //Освободить занятые ресурсы
    {
     for (int r=0; r<Rows; r++)
      for (int c=0; c<Cols; c++)
       Cells[r][c].Free();
    }


#pragma package(smart_init)
