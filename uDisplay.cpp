//---------------------------------------------------------------------------


#pragma hdrstop

#include "uDisplay.h"

//---------------------------------------------------------------------------
void DisplayFile::desenha(TCanvas* canvas, Janela mundo, Janela vp,
                          int poligonoSelecionado, int pontoSelecionado, int tipoReta){
        canvas->Pen->Color = clBlack;
        canvas->Pen->Width = 1;

        canvas->Brush->Color = clWhite;
        canvas->FillRect(Rect(0,0,500,500));

        for (unsigned int i = 0; i < poligonos.size(); i++){
                poligonos[i].desenha(canvas, mundo, vp, tipoReta, false);
        }
        
        if ( poligonoSelecionado >=0 ){
                poligonos[poligonoSelecionado].desenha(canvas, mundo, vp, tipoReta, true);
                if ( pontoSelecionado >=0){
                        poligonos[poligonoSelecionado].destacaPonto(canvas,
                                mundo, vp, pontoSelecionado);
                }
        }
};

void DisplayFile::removePoligono(int indice){
        poligonos.erase(&poligonos[indice]);
        for ( unsigned int i = indice; i < poligonos.size(); i++){
                poligonos[i].id--;
        }
};
#pragma package(smart_init)
