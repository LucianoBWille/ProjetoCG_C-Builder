//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

#include "uJanela.h"

//---------------------------------------------------------------------------
class Ponto{
        public:
                double x,y;
                
        Ponto(double, double);
        Ponto();
        int XW2VP(Janela mundo, Janela vp);
        int YW2VP(Janela mundo, Janela vp);
};
#endif
