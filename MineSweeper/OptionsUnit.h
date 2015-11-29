//---------------------------------------------------------------------------

#ifndef OptionsUnitH
#define OptionsUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TOptionForm : public TForm
{
__published:	// IDE-managed Components
        TLabeledEdit *edMines;
        TLabeledEdit *edRows;
        TLabeledEdit *edCols;
        TColorBox *ColorBoxNormal;
        TColorBox *ColorBoxOpened;
        TColorBox *ColorBoxMarked;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TBitBtn *BitBtn1;
        TLabeledEdit *edSize;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall edMinesChange(TObject *Sender);
        void __fastcall edRowsChange(TObject *Sender);
        void __fastcall edColsChange(TObject *Sender);
        void __fastcall ColorBoxNormalChange(TObject *Sender);
        void __fastcall ColorBoxOpenedChange(TObject *Sender);
        void __fastcall ColorBoxMarkedChange(TObject *Sender);
        void __fastcall edSizeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOptionForm(TComponent* Owner);
        int HowMany; //Мин
        int Rows; //Строк поля
        int Cols;
        int Size; //Размер клетки
        TColor OpenedColor;
        TColor MarkedColor;
        TColor NormalColor;
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionForm *OptionForm;
//---------------------------------------------------------------------------
#endif
