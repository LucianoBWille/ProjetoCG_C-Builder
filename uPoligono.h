//---------------------------------------------------------------------------

#ifndef uPoligonosH
#define uPoligonosH

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#include <ExtCtrls.hpp>

#include "uPonto.h"

//---------------------------------------------------------------------------
class Poligono{
        public:
                vector<Ponto> pontos;
                int id;
                char tipo;

                Poligono();
                void desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta, bool destaca);
                void desenhaNormal(TCanvas* canvas, Janela mundo, Janela vp, bool destaca);
                void desenhaDDA(TCanvas* canvas, Janela mundo, Janela vp, bool destaca);
                void desenhaBresenham(TCanvas* canvas, Janela mundo, Janela vp, bool destaca);
                void removePonto(int indice);
                void destacaPonto(TCanvas* canvas, Janela mundo, Janela vp, int indice);
                Poligono criaPoligonoCirculo(int r);
                void transladaNormal(float dx, float dy);
                void escalonaNormal(float sx, float sy);
                void rotacionaNormal(float angulo);
                Ponto calculaCentroPoligono();
                void Homogeniza(bool trans, bool escal, bool rota, float dx,
                                float dy, float sx, float sy, float angulo);



};
#endif
 
 
 
