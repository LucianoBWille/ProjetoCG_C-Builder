//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

#include <ExtCtrls.hpp>

#include "uJanela.h"
//---------------------------------------------------------------------------
class Ponto{
        public:
                double x,y;
                
        Ponto(double nx, double ny);
        Ponto();
        int XW2VP(Janela mundo, Janela vp);
        int YW2VP(Janela mundo, Janela vp);
        void transladaNormal(float dx, float dy);
        void escalonaNormal(float sx, float sy);
        void rotacionaNormal(float angulo);
        void Homogeneo(float matrizDeMudanca[3][3]);
        void destacaPonto(TCanvas* canvas, Janela mundo, Janela vp);
        int naAreaDeClippingSimples(Janela areaDeClipping);
        int calculaValorClippingDeCohen(Janela areaDeClipping);

};
#endif
 