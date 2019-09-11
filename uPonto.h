//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

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
        void Homogeneo(float m0[3], float m1[3], float m2[3]);

};
#endif
