//---------------------------------------------------------------------------


#pragma hdrstop

#include "uPoligono.h"

//---------------------------------------------------------------------------
Poligono::Poligono(){
  tipo = 'N';
};

void Poligono::desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta, bool destaca){
        switch(tipoReta){
                case 0: desenhaNormal(canvas, mundo, vp, destaca);
                        break;
                case 1: desenhaDDA(canvas, mundo, vp, destaca);
                        break;
                case 3: desenhaBresenham(canvas, mundo, vp, destaca);
                        break;
        }
};

void Poligono::desenhaNormal(TCanvas* canvas, Janela mundo, Janela vp, bool destaca){
        if(destaca)
                canvas->Pen->Width = 3;
        for (unsigned int i = 0; i < pontos.size(); i++){
                if(i == 0){
                        canvas->MoveTo(pontos[i].XW2VP(mundo, vp),pontos[i].YW2VP(mundo, vp));
                }else{
                        canvas->LineTo(pontos[i].XW2VP(mundo, vp),pontos[i].YW2VP(mundo, vp));
                }
        }
};

void Poligono::desenhaDDA(TCanvas* canvas, Janela mundo, Janela vp, bool destaca){
        #define SIGN(x)  ((x) < 0 ? (-1): (1))
        #define ABS(x)   ((x) < 0 ? (-x): (x))
        #define FLOOR(x) ((x) < 0 ? ((x) - (int)(x) != 0 ? ((int)(x) - 1) : ((int)(x))) : (int)(x))

        for(unsigned int j = 1; j < pontos.size(); j++){
                float length, deltax, deltay;
                float x, y, x1, x2, y1, y2;
                x1 = pontos[j-1].XW2VP(mundo, vp);
                y1 = pontos[j-1].YW2VP(mundo, vp);
                x2 = pontos[j].XW2VP(mundo, vp);
                y2 = pontos[j].YW2VP(mundo, vp);

                if( ABS((x2 - x1)) >= ABS((y2-y1)))
                        length = (int)ABS((x2-x1));
                else
                        length = (int)ABS((y2-y1));

                deltax = (float) (x2 - x1) / (float) length;
                deltay = (float) (y2 - y1) / (float) length;
                x = x1 + 0.5*SIGN(deltax);
                y = y1 + 0.5*SIGN(deltay);

                for (int i = 0; i < length; i++){
                        canvas->Pixels[FLOOR(x)][FLOOR(y)] = clRed;
                        if(destaca){
                                canvas->Pixels[FLOOR(x+1)][FLOOR(y)] = clRed;
                                canvas->Pixels[FLOOR(x-1)][FLOOR(y)] = clRed;
                                canvas->Pixels[FLOOR(x)][FLOOR(y+1)] = clRed;
                                canvas->Pixels[FLOOR(x)][FLOOR(y-1)] = clRed;
                        }
                        x+=deltax;
                        y+=deltay;
                }
        }
};

void Poligono::desenhaBresenham(TCanvas* canvas, Janela mundo, Janela vp, bool destaca){

        #define SIGN(x)  ((x) < 0 ? (-1): (1))
        #define ABS(x)   ((x) < 0 ? (-x): (x))
        #define FLOOR(x) ((x) < 0 ? ((x) - (int)(x) != 0 ? ((int)(x) - 1) : ((int)(x))) : (int)(x))

        float e, erro;
        bool interchange;
        int x, y, x1, x2, y1, y2, deltax, deltay, signalx, signaly, tmp;

        for(unsigned int j = 1; j < pontos.size(); j++){

                x1 = pontos[j-1].XW2VP(mundo, vp);
                y1 = pontos[j-1].YW2VP(mundo, vp);
                x2 = pontos[j].XW2VP(mundo, vp);
                y2 = pontos[j].YW2VP(mundo, vp);

                deltax = ABS ((x2-x1));
                deltay = ABS ((y2-y1));
                signalx = SIGN ((x2-x1));
                signaly = SIGN ((y2-y1));
                x = x1;
                y = y1;
                if(signalx < 0 )
                        x-=1;
                if(signaly < 0)
                        y-=1;
                interchange = false;
                if(deltay>deltax){
                        tmp = deltax;
                        deltax = deltay;
                        deltay = tmp;
                        interchange = true;
                }
                erro = 2*deltay-deltax;
                for(int i = 0; i < deltax; i++){
                        canvas->Pixels[x][y] = clBlue;
                        if(destaca != destaca){
                                canvas->Pixels[x+1][y] = clBlue;
                                canvas->Pixels[x-1][y] = clBlue;
                                canvas->Pixels[x][y+1] = clBlue;
                                canvas->Pixels[x][y-1] = clBlue;
                        }
                        while(erro>=0){
                                if(interchange)
                                        x = x + signalx;
                                else
                                        y = y + signaly;
                                erro = erro - 2*deltax;
                        }
                        if(interchange)
                                y = y + signaly;
                        else
                                x = x + signalx;
                        erro = erro + 2*deltay;
                }
        }
};

void Poligono::removePonto(int indice){
        pontos.erase(&pontos[indice]);
};

void Poligono::destacaPonto(TCanvas* canvas, Janela mundo, Janela vp, int indice){
        int x = pontos[indice].XW2VP(mundo, vp);
        int y = pontos[indice].YW2VP(mundo, vp);
        canvas->Pen->Width = 3;
        int tam = 5;
        canvas->Ellipse( x - tam, y - tam, x + tam, y + tam );
};

#pragma package(smart_init)
