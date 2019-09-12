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

void DisplayFile::clippPoligonosPorPonto(Janela areaDeClipping, int *contaId){
        for(unsigned int i = 0; i < poligonos.size(); i++){
                poligonos[i].clippPoligonoPorPonto(areaDeClipping);
        }
        if(poligonos[0].pontos.size() != 5 ||
                (poligonos[0].pontos[0].x != areaDeClipping.xMin &&
                poligonos[0].pontos[0].y != areaDeClipping.yMax &&
                poligonos[0].pontos[1].x != areaDeClipping.xMax &&
                poligonos[0].pontos[1].y != areaDeClipping.yMax)){  
                Poligono poligonoAuxiliar;
                poligonoAuxiliar.pontos.push_back(Ponto(areaDeClipping.xMin,
                                                        areaDeClipping.yMax));
                poligonoAuxiliar.pontos.push_back(Ponto(areaDeClipping.xMax,
                                                        areaDeClipping.yMax));
                poligonoAuxiliar.pontos.push_back(Ponto(areaDeClipping.xMax,
                                                        areaDeClipping.yMin));
                poligonoAuxiliar.pontos.push_back(Ponto(areaDeClipping.xMin,
                                                        areaDeClipping.yMin));
                poligonoAuxiliar.pontos.push_back(Ponto(areaDeClipping.xMin,
                                                        areaDeClipping.yMax));
                poligonoAuxiliar.id = 0;
                *contaId = *contaId+1;
                poligonos.insert(poligonos.begin(), poligonoAuxiliar);
                for(unsigned int i = 1; i < poligonos.size(); i++){
                        poligonos[i].id++;
                }     
        }
        int tamanho = poligonos.size();
        for(int i = 0; i < tamanho; i++){
                if(poligonos[i].pontos.size() == 0){
                        poligonos.erase(poligonos.begin()+i);
                        i--;
                        tamanho--;
                        for(int j = i; j < tamanho; j++){
                                poligonos[j].id = j;
                        }
                        *contaId = *contaId-1;
                }
        }
};
#pragma package(smart_init)
