//---------------------------------------------------------------------------

#ifndef uDisplayH
#define uDisplayH

#include <vector>

#include <ExtCtrls.hpp>

#include "uPoligono.h"

using namespace std;

//---------------------------------------------------------------------------
class DisplayFile{
        public:
                vector<Poligono> poligonos;
        void desenha(TCanvas* canvas, Janela mundo, Janela vp,
                int poligonoSelecionado, int pontoSelecionado, int tipoReta);
        void removePoligono(int indice);
};
#endif
  

