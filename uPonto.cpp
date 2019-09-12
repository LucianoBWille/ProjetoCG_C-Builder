//---------------------------------------------------------------------------


#pragma hdrstop

#include "uPonto.h"

#include <math.h>

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

void Ponto::transladaNormal(float dx, float dy){
        this->x += dx;
        this->y += dy;
};

void Ponto::escalonaNormal(float sx, float sy){
        this->x = this->x * sx;
        this->y = this->y * sy;
};

void Ponto::rotacionaNormal(float angulo){
        float aux = this->x;
        this->x = this->x * cos(angulo) - this->y * sin(angulo);
        this->y = aux * sin(angulo) + this->y * cos(angulo);
};

void Ponto::Homogeneo(float matrizDeMudanca[3][3]){
        float pontoAuxiliar[1][3], pontoFinal[1][3], soma = 0;

        pontoAuxiliar[0][0] = this->x;
        pontoAuxiliar[0][1] = this->y;
        pontoAuxiliar[0][2] = 1;
        for(unsigned int j=0; j<3; j++)
        {
                for(unsigned int k=0; k<3; k++)
                {
                        soma += pontoAuxiliar[0][k] * matrizDeMudanca[k][j];
                }
                pontoFinal[0][j] = soma;
                soma = 0;
        }
        this->x = pontoFinal[0][0];
        this->y = pontoFinal[0][1];
};
#pragma package(smart_init)
