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

void Ponto::Homogeneo(float m0[3], float m1[3], float m2[3]){
        float p[1][3], p1[1][3], sum = 0, m[3][3];

        m[0][0] = m0[0];
        m[0][1] = m0[1];
        m[0][2] = m0[2];
        m[1][0] = m1[0];
        m[1][1] = m1[1];
        m[1][2] = m1[2];
        m[2][0] = m2[0];
        m[2][1] = m2[1];
        m[2][2] = m2[2];

        p[0][0] = this->x;
        p[0][1] = this->y;
        p[0][2] = 1;
        for(unsigned int i=0; i<1; i++)
	{
		for(unsigned int j=0; j<3; j++)
		{
			for(unsigned int k=0; k<3; k++)
			{
				sum += p[i][k] * m[k][j];
			}
			p1[i][j]=sum;
			sum=0;
		}
	}
        this->x = p1[0][0];
        this->y = p1[0][1];
};
#pragma package(smart_init)
