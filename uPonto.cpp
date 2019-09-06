//---------------------------------------------------------------------------


#pragma hdrstop

#include "uPonto.h"

//---------------------------------------------------------------------------
Ponto::Ponto(double nx, double ny){
        x = nx;
        y = ny;
}
Ponto::Ponto(){
        x = y = 1;
};
int Ponto::XW2VP(Janela mundo, Janela vp){
        return (this->x - mundo.xMin)/(mundo.xMax - mundo.xMin)*(vp.xMax - vp.xMin);
};
int Ponto::YW2VP(Janela mundo, Janela vp){
        return (1-((this->y - mundo.yMin)/(mundo.yMax - mundo.yMin)))*(vp.yMax - vp.yMin);
};
#pragma package(smart_init)