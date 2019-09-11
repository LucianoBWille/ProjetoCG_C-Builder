//---------------------------------------------------------------------------


#pragma hdrstop

#include "uPoligono.h"

#include <math.h>

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
                case 2: desenhaBresenham(canvas, mundo, vp, destaca);
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
                        if(destaca){
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

Poligono Poligono::criaPoligonoCirculo(int r){
        vector<Poligono> parte;
        Poligono p0;
        parte.push_back(p0);
        Poligono p1;
        parte.push_back(p1);   
        Poligono p2;
        parte.push_back(p2);
        Poligono p3;
        parte.push_back(p3);
        Poligono p4;
        parte.push_back(p4);
        Poligono p5;
        parte.push_back(p5);
        Poligono p6;
        parte.push_back(p6);
        Poligono p7;
        parte.push_back(p7);
        Poligono pol;

        int x, y, p;
        x = 0;
        y = r;
        p = 1 - r;
        int aux = 0.7071067811865*r;
        parte[0].pontos.push_back(Ponto(r, 0));
        parte[1].pontos.push_back(Ponto(aux, aux));
        parte[2].pontos.push_back(Ponto(0, r));
        parte[3].pontos.push_back(Ponto(-aux, aux));
        parte[4].pontos.push_back(Ponto(-r, 0));
        parte[5].pontos.push_back(Ponto(-aux, -aux));
        parte[6].pontos.push_back(Ponto(0, -r));
        parte[7].pontos.push_back(Ponto(aux, -aux));
        while(x < y){
                if(p < 0){
                        x++;
                        p += 2 * x + 1;
                }else{
                        x++;
                        y--;
                        p += 2 * (x - y) + 1;
                }    
                if (x < y){
                        parte[0].pontos.push_back(Ponto(y, x));
                        parte[1].pontos.insert(parte[1].pontos.begin() + 1, Ponto(x,y));
                        parte[2].pontos.push_back(Ponto(-x, y));
                        parte[3].pontos.insert(parte[3].pontos.begin() + 1, Ponto(-y, x));
                        parte[4].pontos.push_back(Ponto(-y, -x));
                        parte[5].pontos.insert(parte[5].pontos.begin() + 1, Ponto(-x, -y));
                        parte[6].pontos.push_back(Ponto(x, -y));
                        parte[7].pontos.insert(parte[7].pontos.begin() + 1, Ponto(y, -x));
                }
        }
        for(unsigned int i = 0; i<8; i++){
                for(unsigned int j=0; j<parte[i].pontos.size(); j++){
                        pol.pontos.push_back(parte[i].pontos[j]);
                }
        }
        pol.pontos.push_back(parte[0].pontos[0]);
        return pol;

};

void Poligono::transladaNormal(float dx, float dy){
        for(unsigned int i = 0; i < pontos.size(); i++){
                pontos[i].transladaNormal(dx, dy);
        }
};

void Poligono::escalonaNormal(float sx, float sy){
        for(unsigned int i = 0; i < pontos.size(); i++){
                pontos[i].escalonaNormal(sx, sy);
        }
};

void Poligono::rotacionaNormal(float angulo){
        float angRad = (M_PI / 180) * angulo;
        for(unsigned int i = 0; i < pontos.size(); i++){
                pontos[i].rotacionaNormal(angRad);
        }
};

Ponto Poligono::calculaCentroPoligono(){
        double maiorX, maiorY, menorX, menorY;
        for (unsigned int i = 0; i < pontos.size(); i++){
                if(i==0){
                        maiorX = pontos[i].x;
                        maiorY = pontos[i].y;
                        menorX = pontos[i].x;
                        menorY = pontos[i].y;
                }else{
                        if(maiorX < pontos[i].x){
                                maiorX = pontos[i].x;
                        }else{
                                if(menorX > pontos[i].x){
                                        menorX = pontos[i].x;
                                }
                        }
                        if(maiorY < pontos[i].y){
                                maiorY = pontos[i].y;
                        }
                        else{
                                if(menorY > pontos[i].y){
                                        menorY = pontos[i].y;
                                }
                        }
                }
        }
        Ponto p;
        p.x = (maiorX + menorX)/2;
        p.y = (maiorY + menorY)/2;
        return p;
};

void Poligono::Homogeniza(bool trans, bool escal, bool rota, float dx,
                                float dy, float sx, float sy, float angulo){
        float t1[3][3], esc[3][3], rot[3][3], t[3][3], t2[3][3], m[3][3], mf[3][3];
        float angRad = (M_PI / 180) * angulo, sum = 0;
        Ponto centro = calculaCentroPoligono();
        t1[0][0] = 1;
        t1[0][1] = 0;
        t1[0][2] = 0;
        t1[1][0] = 0;
        t1[1][1] = 1;
        t1[1][2] = 0;
        t1[2][0] = -centro.x;
        t1[2][1] = -centro.y;
        t1[2][2] = 1;

        esc[0][0] = sx;
        esc[0][1] = 0;
        esc[0][2] = 0;
        esc[1][0] = 0;
        esc[1][1] = sy;
        esc[1][2] = 0;
        esc[2][0] = 0;
        esc[2][1] = 0;
        esc[2][2] = 1;

        rot[0][0] = cos(angRad);
        rot[0][1] = sin(angRad);
        rot[0][2] = 0;
        rot[1][0] = -sin(angRad);
        rot[1][1] = cos(angRad);
        rot[1][2] = 0;
        rot[2][0] = 0;
        rot[2][1] = 0;
        rot[2][2] = 1;

        t[0][0] = 1;
        t[0][1] = 0;
        t[0][2] = 0;
        t[1][0] = 0;
        t[1][1] = 1;
        t[1][2] = 0;
        t[2][0] = dx;
        t[2][1] = dy;
        t[2][2] = 1;

        t2[0][0] = 1;
        t2[0][1] = 0;
        t2[0][2] = 0;
        t2[1][0] = 0;
        t2[1][1] = 1;
        t2[1][2] = 0;
        t2[2][0] = centro.x;
        t2[2][1] = centro.y;
        t2[2][2] = 1;

        m[0][0] = 1;
        m[0][1] = 0;
        m[0][2] = 0;
        m[1][0] = 0;
        m[1][1] = 1;
        m[1][2] = 0;
        m[2][0] = 0;
        m[2][1] = 0;
        m[2][2] = 1;

        for(unsigned int i=0; i<3; i++)
	{
		for(unsigned int j=0; j<3; j++)
		{
			for(unsigned int k=0; k<3; k++)
			{
				sum += m[i][k] * t1[k][j];
			}
			mf[i][j]=sum;
			sum=0;
		}
	}
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        m[i][j]=mf[i][j];
                }
        }
        if(trans){
                for(unsigned int i=0; i<3; i++)
	        {
		        for(unsigned int j=0; j<3; j++)
		        {
			        for(unsigned int k=0; k<3; k++)
			        {
				        sum += m[i][k] * t[k][j];
			        }
			        mf[i][j]=sum;
			        sum=0;
		        }
	        }
        }   
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        m[i][j]=mf[i][j];
                }
        }
        if(escal){
                for(unsigned int i=0; i<3; i++)
	        {
		        for(unsigned int j=0; j<3; j++)
		        {
			        for(unsigned int k=0; k<3; k++)
			        {
				        sum += m[i][k] * esc[k][j];
			        }
			        mf[i][j]=sum;
			        sum=0;
		        }
	        }
        }   
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        m[i][j]=mf[i][j];
                }
        }
        if(rota){
                for(unsigned int i=0; i<3; i++)
	        {
		        for(unsigned int j=0; j<3; j++)
		        {
			        for(unsigned int k=0; k<3; k++)
			        {
				        sum += m[i][k] * rot[k][j];
			        }
			        mf[i][j]=sum;
			        sum=0;
		        }
	        }
        }    
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        m[i][j]=mf[i][j];
                }
        }
        for(unsigned int i=0; i<3; i++)
	{
		for(unsigned int j=0; j<3; j++)
		{
			for(unsigned int k=0; k<3; k++)
			{
				sum += m[i][k] * t2[k][j];
			}
			mf[i][j]=sum;
			sum=0;
		}
	}

        for(unsigned int i = 0; i < pontos.size(); i++){
                pontos[i].Homogeneo(mf[0], mf[1], mf[2]);
        }
};

#pragma package(smart_init)
