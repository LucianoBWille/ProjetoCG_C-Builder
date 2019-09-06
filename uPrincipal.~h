//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <uJanela.h>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *LabelCoordenadaVP;
        TLabel *LabelCoordenadaMundo;
        TImage *Image1;
        TButton *BtnNovoComMouse;
        TListBox *ListBoxPoligonos;
        TLabel *LabelPoligonos;
        TListBox *ListBoxPontos;
        TLabel *LabelPontos;
        TEdit *EdXmin;
        TEdit *EdYmin;
        TEdit *EdXmax;
        TEdit *EdYmax;
        TLabel *LabelXmin;
        TLabel *LabelXmax;
        TLabel *LabelYmin;
        TLabel *LabelYmax;
        TButton *BtnAtulizar;
        TButton *BtnResetar;
        TButton *BtnZoomIn;
        TButton *BtnZoomOut;
        TSpeedButton *SpeedBtnUp;
        TSpeedButton *SpeedBtnDown;
        TSpeedButton *SpeedBtnRight;
        TSpeedButton *SpeedBtnLeft;
        TSpeedButton *SpeedBtnCenter;
        TButton *BtnRemoverPoligono;
        TButton *BtnRemoverPonto;
        TButton *BtnDesselecionar;
        TRadioGroup *RadioGroup1;
        TPageControl *PageControl1;
        TTabSheet *TabSheetPoligonos;
        TTabSheet *TabSheetMundoVP;
        TPageControl *PageControl2;
        TTabSheet *TabSheetdicionaPoligono;
        TEdit *Edit1;
        TLabel *Label1;
        TTabSheet *TabSheet1;
        TPageControl *PageControl3;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall BtnNovoComMouseClick(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BtnAtulizarClick(TObject *Sender);
        void __fastcall BtnResetarClick(TObject *Sender);
        void __fastcall BtnZoomInClick(TObject *Sender);
        void __fastcall BtnZoomOutClick(TObject *Sender);
        void __fastcall SpeedBtnUpClick(TObject *Sender);
        void __fastcall SpeedBtnDownClick(TObject *Sender);
        void __fastcall SpeedBtnLeftClick(TObject *Sender);
        void __fastcall SpeedBtnRightClick(TObject *Sender);
        void __fastcall SpeedBtnCenterClick(TObject *Sender);
        void __fastcall BtnAtualizaLstaPolClick(TObject *Sender);
        void __fastcall BtnVerPontosClick(TObject *Sender);
        void __fastcall ListBoxPoligonosClick(TObject *Sender);
        void __fastcall BtnRemoverPoligonoClick(TObject *Sender);
        void __fastcall BtnRemoverPontoClick(TObject *Sender);
        void __fastcall ListBoxPontosClick(TObject *Sender);
        void __fastcall BtnDesselecionarClick(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        void atualizaCoordenadaMundo();
        void atualizaListaPoligonos();
        void atualizaListaPontos();
        void desselecionaPoligonos();
        void desselecionaPontos();
        double XVP2W(int xVP, Janela, Janela);
        double YVP2W(int xVP, Janela, Janela);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
