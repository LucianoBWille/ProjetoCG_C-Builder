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
                Ponto calculaCentroPoligono();

};
#endif
 
 
 
