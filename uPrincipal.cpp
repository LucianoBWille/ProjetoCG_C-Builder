//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uPrincipal.h"
#include "uDisplay.h"
#include "uPoligono.h"
#include "uPonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Ponto aux;
Janela mundo(-250.0,-250.0,250.0,250.0);
Janela vp(0,0,500,500);
Janela areaDeClipping(-100, -100, 100, 100);
Poligono poligono;
DisplayFile display;
int contaId=0;
bool novo = false;
int tempIndexListBoxPoligonos = -1;
int tempIndexListBoxPontos = -1;
int tipoReta = 0;
int tipoClipping = 0;

//---------------------------------------------------------------------------
void TForm1::atualizaView(){
        display.desenha(Image1->Canvas, mundo, vp, tempIndexListBoxPoligonos,
                                        tempIndexListBoxPontos, tipoReta);
        atualizaListaPoligonos();
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        //Eixo Vertical
        poligono.pontos.push_back(Ponto(0.0, mundo.yMax));
        poligono.pontos.push_back(Ponto(0.0, mundo.yMin));

        poligono.id = contaId++;
        display.poligonos.push_back(poligono);
        poligono.pontos.clear();

        //Eixo Horizontal
        poligono.pontos.push_back(Ponto(mundo.xMin, 0.0));
        poligono.pontos.push_back(Ponto(mundo.xMax, 0.0));

        poligono.id = contaId++;
        display.poligonos.push_back(poligono);
        poligono.pontos.clear();

        atualizaView();
        atualizaListaPoligonos();

        RadioGroup1->Items->Add("Normal");
        RadioGroup1->Items->Add("DDA");
        RadioGroup1->Items->Add("Bresenham");
        RadioGroup1->ItemIndex = 0;

        RadioGroupClipping->Items->Add("Sem Clipping");
        RadioGroupClipping->Items->Add("Clipping de pontos");
        RadioGroupClipping->Items->Add("Clipping de linha");
        RadioGroupClipping->ItemIndex = 0;
}
//---------------------------------------------------------------------------
double TForm1::XVP2W(int xVP, Janela mundo, Janela vp){
        return (xVP - vp.xMin)/(vp.xMax - vp.xMin) * (mundo.xMax - mundo.xMin) + mundo.xMin;
};
//---------------------------------------------------------------------------
double TForm1::YVP2W(int yVP, Janela mundo, Janela vp){
        return (1-(yVP - vp.yMin)/(vp.yMax - vp.yMin)) * (mundo.yMax - mundo.yMin) + mundo.yMin;
};
//---------------------------------------------------------------------------
void TForm1::atualizaCoordenadaMundo(){
        mundo.xMin = StrToFloat(EdXmin->Text);
        mundo.yMin = StrToFloat(EdYmin->Text);
        mundo.xMax = StrToFloat(EdXmax->Text);
        mundo.yMax = StrToFloat(EdYmax->Text);

        if(display.poligonos[0].pontos.size() != 5 ||
                (display.poligonos[0].pontos[0].x != areaDeClipping.xMin &&
                display.poligonos[0].pontos[0].y != areaDeClipping.yMax &&
                display.poligonos[0].pontos[1].x != areaDeClipping.xMax &&
                display.poligonos[0].pontos[1].y != areaDeClipping.yMax)){

                display.poligonos[0].pontos[0].y = mundo.yMax;
                display.poligonos[0].pontos[1].y = mundo.yMin;
                display.poligonos[1].pontos[0].x = mundo.xMin;
                display.poligonos[1].pontos[1].x = mundo.xMax;
        }else{
                display.poligonos[1].pontos[0].y = mundo.yMax;
                display.poligonos[1].pontos[1].y = mundo.yMin;
                display.poligonos[2].pontos[0].x = mundo.xMin;
                display.poligonos[2].pontos[1].x = mundo.xMax;
        }

        atualizaView();
}
//---------------------------------------------------------------------------
void TForm1::atualizaListaPoligonos(){
        ListBoxPoligonos->Items->Clear();
        for (unsigned int i = 0; i < display.poligonos.size(); i++){
                String aux = IntToStr(display.poligonos[i].id) + " - "
                        + display.poligonos[i].tipo + " - "
                        + IntToStr(display.poligonos[i].pontos.size());
                ListBoxPoligonos->Items->Add(aux);
        }
        ListBoxPoligonos->ItemIndex = tempIndexListBoxPoligonos;
        atualizaListaPontos();
}
//---------------------------------------------------------------------------
void TForm1::atualizaListaPontos(){
        ListBoxPontos->Items->Clear();
        int index = ListBoxPoligonos->ItemIndex;
        tempIndexListBoxPoligonos = index;
        float x,y;
        if(index >= 0){
                for (unsigned int i = 0; i < display.poligonos[index].pontos.size(); i++){
                        x = display.poligonos[index].pontos[i].x;
                        y = display.poligonos[index].pontos[i].y;
                        String aux = "P" + IntToStr(i) + " ( " +
                                                FloatToStr(x) + "; " +
                                                FloatToStr(y) + " )";
                        ListBoxPontos->Items->Add(aux);
                }
        }else{
                ListBoxPontos->Items->Clear();
                desselecionaPontos();
        }
}
//---------------------------------------------------------------------------
void TForm1::desselecionaPoligonos(){
        ListBoxPoligonos->ItemIndex = -1;
        tempIndexListBoxPoligonos = -1;
        desselecionaPontos();
}
//---------------------------------------------------------------------------
void TForm1::desselecionaPontos(){
        ListBoxPontos->ItemIndex = -1;
        tempIndexListBoxPontos = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        double xW, yW;
        LabelCoordenadaVP->Caption = "ViewPort = ( " + IntToStr(X) +
                                        "; " + IntToStr(Y) + " )";

        xW = XVP2W(X, mundo, vp);
        yW = YVP2W(Y, mundo, vp);

        LabelCoordenadaMundo->Caption = "Mundo = ( " + FloatToStr(xW) +
                                        "; " + FloatToStr(yW) + " )";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnNovoComMouseClick(TObject *Sender)
{
        novo = true;
        desselecionaPoligonos();
        desselecionaPontos();
        atualizaView();
        atualizaListaPoligonos();
};
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        double xW, yW;
        if(novo){
                if(Button == mbLeft){
                        xW = XVP2W(X, mundo, vp);
                        yW = YVP2W(Y, mundo, vp);
                        poligono.pontos.push_back(Ponto(xW, yW));
                        Image1->Canvas->Pen->Width = 3;
                        poligono.desenha(Image1->Canvas, mundo, vp, tipoReta, true);
                }
                else
                {
                        poligono.id = contaId++;
                        display.poligonos.push_back(poligono);
                        poligono.pontos.clear();

                        novo = false;

                        tempIndexListBoxPoligonos = display.poligonos.size()-1;
                        desselecionaPontos();
                        atualizaView();
                        atualizaListaPoligonos();
                }
        }else{
                ShowMessage("Clique em 'Novo Poligono'");
        }
};
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnAtulizarClick(TObject *Sender)
{
        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnResetarClick(TObject *Sender)
{
        EdXmin->Text = "-250,0";
        EdYmin->Text = "-250,0";
        EdXmax->Text = "250,0";
        EdYmax->Text = "250,0";

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnZoomInClick(TObject *Sender)
{                                        
        float passo = StrToFloat(Edit1->Text);
        EdXmin->Text = FloatToStr(StrToFloat(EdXmin->Text)*(1-passo));
        EdYmin->Text = FloatToStr(StrToFloat(EdYmin->Text)*(1-passo));
        EdXmax->Text = FloatToStr(StrToFloat(EdXmax->Text)*(1-passo));
        EdYmax->Text = FloatToStr(StrToFloat(EdYmax->Text)*(1-passo));

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnZoomOutClick(TObject *Sender)
{
        float passo = StrToFloat(Edit1->Text);
        EdXmin->Text = FloatToStr(StrToFloat(EdXmin->Text)*(1+passo));
        EdYmin->Text = FloatToStr(StrToFloat(EdYmin->Text)*(1+passo));
        EdXmax->Text = FloatToStr(StrToFloat(EdXmax->Text)*(1+passo));
        EdYmax->Text = FloatToStr(StrToFloat(EdYmax->Text)*(1+passo));

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnUpClick(TObject *Sender)
{                  
        float passo = StrToFloat(Edit1->Text)/2;
        float y = mundo.yMax - mundo.yMin;
        EdYmin->Text = mundo.yMin + y*passo;
        EdYmax->Text = mundo.yMax + y*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnDownClick(TObject *Sender)
{                 
        float passo = StrToFloat(Edit1->Text)/2;
        float y = mundo.yMax - mundo.yMin;
        EdYmin->Text = mundo.yMin - y*passo;
        EdYmax->Text = mundo.yMax - y*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnLeftClick(TObject *Sender)
{             
        float passo = StrToFloat(Edit1->Text)/2;
        float x = mundo.xMax - mundo.xMin;
        EdXmin->Text = mundo.xMin - x*passo;
        EdXmax->Text = mundo.xMax - x*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnRightClick(TObject *Sender)
{            
        float passo = StrToFloat(Edit1->Text)/2;
        float x = mundo.xMax - mundo.xMin;
        EdXmin->Text = mundo.xMin + x*passo;
        EdXmax->Text = mundo.xMax + x*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnCenterClick(TObject *Sender)
{
        EdXmin->Text = FloatToStr(-(mundo.xMax - mundo.xMin)/2);
        EdYmin->Text = FloatToStr(-(mundo.yMax - mundo.yMin)/2);
        EdXmax->Text = FloatToStr( (mundo.xMax - mundo.xMin)/2);
        EdYmax->Text = FloatToStr( (mundo.yMax - mundo.yMin)/2);

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnUpRightClick(TObject *Sender)
{            
        float passo = StrToFloat(Edit1->Text)/2;
        float y = mundo.yMax - mundo.yMin;
        EdYmin->Text = mundo.yMin + y*passo;
        EdYmax->Text = mundo.yMax + y*passo;
        float x = mundo.xMax - mundo.xMin;
        EdXmin->Text = mundo.xMin + x*passo;
        EdXmax->Text = mundo.xMax + x*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnUpLeftClick(TObject *Sender)
{             
        float passo = StrToFloat(Edit1->Text)/2;
        float y = mundo.yMax - mundo.yMin;
        EdYmin->Text = mundo.yMin + y*passo;
        EdYmax->Text = mundo.yMax + y*passo;
        float x = mundo.xMax - mundo.xMin;
        EdXmin->Text = mundo.xMin - x*passo;
        EdXmax->Text = mundo.xMax - x*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnDownLeftClick(TObject *Sender)
{
        float passo = StrToFloat(Edit1->Text)/2;
        float y = mundo.yMax - mundo.yMin;
        EdYmin->Text = mundo.yMin - y*passo;
        EdYmax->Text = mundo.yMax - y*passo;
        float x = mundo.xMax - mundo.xMin;
        EdXmin->Text = mundo.xMin - x*passo;
        EdXmax->Text = mundo.xMax - x*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedBtnDownRightClick(TObject *Sender)
{        
        float passo = StrToFloat(Edit1->Text)/2;
        float y = mundo.yMax - mundo.yMin;
        EdYmin->Text = mundo.yMin - y*passo;
        EdYmax->Text = mundo.yMax - y*passo;
        float x = mundo.xMax - mundo.xMin;
        EdXmin->Text = mundo.xMin + x*passo;
        EdXmax->Text = mundo.xMax + x*passo;

        atualizaCoordenadaMundo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnAtualizaLstaPolClick(TObject *Sender)
{
        atualizaListaPoligonos();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnVerPontosClick(TObject *Sender)
{
        atualizaListaPontos();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBoxPoligonosClick(TObject *Sender)
{
        tempIndexListBoxPoligonos = ListBoxPoligonos->ItemIndex;
        desselecionaPontos();
        atualizaView();
        atualizaListaPontos();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnRemoverPoligonoClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                if(6 == IntToStr(Application->MessageBoxA("Quer mesmo excluir o poligono?",
                 "Comfirmação", MB_YESNO))){
                        display.removePoligono(ListBoxPoligonos->ItemIndex);
                        desselecionaPoligonos();
                        desselecionaPontos();
                        atualizaView();
                        atualizaListaPoligonos();
                        contaId--;
                 }
        }else{
                if(ListBoxPoligonos->ItemIndex >= 0){
                        ShowMessage("Você não pode remover os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para remover!");
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnRemoverPontoClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                if(tempIndexListBoxPontos >=0){
                        if(6 == IntToStr(Application->MessageBoxA("Quer mesmo excluir o ponto?",
                                "Comfirmação", MB_YESNO))){
                                display.poligonos[tempIndexListBoxPoligonos].
                                              removePonto(tempIndexListBoxPontos);
                                desselecionaPontos();
                                atualizaView();
                                atualizaListaPoligonos();
                        }
                }else{
                        ShowMessage("Selecione um poligono para remover!");
                }
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para remover!");
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBoxPontosClick(TObject *Sender)
{
        tempIndexListBoxPontos = ListBoxPontos->ItemIndex;
        display.desenha(Image1->Canvas, mundo, vp, tempIndexListBoxPoligonos,
                                        tempIndexListBoxPontos, tipoReta);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnDesselecionarClick(TObject *Sender)
{
        desselecionaPoligonos();
        desselecionaPontos();
        atualizaView();
        atualizaListaPoligonos();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
        tipoReta = RadioGroup1->ItemIndex;
        atualizaView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnNovoCirculoClick(TObject *Sender)
{
        Poligono poligono;
        poligono = poligono.criaPoligonoCirculo(StrToInt(EdRaioCirculo->Text));
        poligono.id = contaId++;
        display.poligonos.push_back(poligono);
        desselecionaPoligonos();
        desselecionaPontos();
        tempIndexListBoxPoligonos = display.poligonos.size()-1;
        atualizaView();
        atualizaListaPoligonos();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnTransladaClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                float x,y;
                x = StrToFloat(EdDxTrans->Text);
                y = StrToFloat(EdDyTrans->Text);
                display.poligonos[tempIndexListBoxPoligonos].transladaNormal(x, y);
                atualizaView();
                atualizaListaPoligonos();
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para mover!");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnEscalonaNormalClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                float x,y;
                x = StrToFloat(EdSxEscalona->Text);
                y = StrToFloat(EdSyEscalona->Text);
                display.poligonos[tempIndexListBoxPoligonos].escalonaNormal(x, y);
                atualizaView();
                atualizaListaPoligonos();
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para escalonar!");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnRefletirTotalClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                display.poligonos[tempIndexListBoxPoligonos].escalonaNormal(-1, -1);
                atualizaView();
                atualizaListaPoligonos();
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para refletir!");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnRefletirEmXClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                display.poligonos[tempIndexListBoxPoligonos].escalonaNormal(-1, 1);
                atualizaView();
                atualizaListaPoligonos();
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para refletir!");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnRefletirEmYClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                display.poligonos[tempIndexListBoxPoligonos].escalonaNormal(1, -1);
                atualizaView();
                atualizaListaPoligonos();
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para refletir!");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnRotacionaNormalClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                float angulo = StrToFloat(EdAnguloRotacao->Text);
                display.poligonos[tempIndexListBoxPoligonos].rotacionaNormal(angulo);
                atualizaView();
                atualizaListaPoligonos();
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para rotacionar!");
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnExeHomoClick(TObject *Sender)
{
        if(tempIndexListBoxPoligonos > 1){
                float dx, dy, sx, sy, angulo;
                dx = StrToFloat(EdDxTrans->Text);
                dy = StrToFloat(EdDyTrans->Text);
                sx = StrToFloat(EdSxEscalona->Text);
                sy = StrToFloat(EdSyEscalona->Text);
                angulo = StrToFloat(EdAnguloRotacao->Text);
                display.poligonos[tempIndexListBoxPoligonos].Homogeniza(
                                Translada->State, Escalona->State, Rotaciona->State,
                                dx, dy, sx, sy, angulo);
                atualizaView();
                atualizaListaPoligonos();

                Ponto pontoCentroPoligono = display.poligonos[
                             tempIndexListBoxPoligonos].calculaCentroPoligono();
                pontoCentroPoligono.destacaPonto(Image1->Canvas, mundo, vp);
                Image1->Canvas->Ellipse(pontoCentroPoligono.XW2VP(mundo, vp)+5,
                                        pontoCentroPoligono.YW2VP(mundo, vp)+5,
                                        pontoCentroPoligono.XW2VP(mundo, vp)-5,
                                        pontoCentroPoligono.YW2VP(mundo, vp)-5);
        }else{
                if(tempIndexListBoxPoligonos >= 0){
                        ShowMessage("Você não pode alterar os eixos!");
                }else{
                        ShowMessage("Selecione um poligono para executara ação homegenea!");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnClippClick(TObject *Sender)
{
        switch(tipoClipping){
                case 0: atualizaView();
                        //atualizaListaPoligonos();
                        break;
                case 1: display.clippPoligonosPorPonto(areaDeClipping, &contaId);
                        atualizaView();
                        //atualizaListaPoligonos();
                        break;
                case 2: display.clippPoligonosPorReta(areaDeClipping, &contaId);
                        atualizaView();
                        //atualizaListaPoligonos();
                        break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroupClippingClick(TObject *Sender)
{
        tipoClipping = RadioGroupClipping->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        ShowMessage(display.poligonos[2].pontos[1].calculaValorClippingDeCohen(areaDeClipping));       
}
//---------------------------------------------------------------------------

