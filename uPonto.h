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
        void translacaoNormal(int dx, int dy);
        void escalonamentoNormal(float variacao);
        void rotacaoNormal(float angulo);
        void reflexao(int tipo);
        void escalonamentoHomogeneo(float variacao);
        void rotacaoHomogenea(float angulo);

};
#endif
