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
        Poligono poligonoResultado;
        for(unsigned int i = 0; i<8; i++){
                for(unsigned int j=0; j<parte[i].pontos.size(); j++){
                        poligonoResultado.pontos.push_back(parte[i].pontos[j]);
                }
        }
        poligonoResultado.pontos.push_back(parte[0].pontos[0]);
        return poligonoResultado;

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
        float anguloEmRadianos = (M_PI / 180) * angulo;
        for(unsigned int i = 0; i < pontos.size(); i++){
                pontos[i].rotacionaNormal(anguloEmRadianos);
        }
};

Ponto Poligono::calculaCentroPoligono(){
        Ponto pontoTemporario;          /*
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
        pontoTemporario.x = (maiorX + menorX)/2;
        pontoTemporario.y = (maiorY + menorY)/2; */

        int tamanhoPontos = pontos.size();
        float somaX = 0, somaY = 0;
        for(int i = 0; i < tamanhoPontos; i++){
                somaX += pontos[i].x;
                somaY += pontos[i].y;
        }
        pontoTemporario.x = somaX/tamanhoPontos;
        pontoTemporario.y = somaY/tamanhoPontos;
        return pontoTemporario;
};

void Poligono::Homogeniza(bool transladaBool, bool escalonaBool, bool rotacionaBool,
                        float dx, float dy, float sx, float sy, float angulo){
        float transladaParaMeioDoMundo[3][3],
                escalonaDoUsuario[3][3],
                rotacionaDoUsuario[3][3],
                transladaDoUsuario[3][3],
                transladaParaOrigemPoligono[3][3],
                matrizAuxiliar[3][3],
                matrizFinal[3][3];
        float anguloEmRadianos = (M_PI / 180) * angulo, soma = 0;
        Ponto pontoCentroPoligono = calculaCentroPoligono();
        transladaParaMeioDoMundo[0][0] = 1;
        transladaParaMeioDoMundo[0][1] = 0;
        transladaParaMeioDoMundo[0][2] = 0;
        transladaParaMeioDoMundo[1][0] = 0;
        transladaParaMeioDoMundo[1][1] = 1;
        transladaParaMeioDoMundo[1][2] = 0;
        transladaParaMeioDoMundo[2][0] = -pontoCentroPoligono.x;
        transladaParaMeioDoMundo[2][1] = -pontoCentroPoligono.y;
        transladaParaMeioDoMundo[2][2] = 1;

        escalonaDoUsuario[0][0] = sx;
        escalonaDoUsuario[0][1] = 0;
        escalonaDoUsuario[0][2] = 0;
        escalonaDoUsuario[1][0] = 0;
        escalonaDoUsuario[1][1] = sy;
        escalonaDoUsuario[1][2] = 0;
        escalonaDoUsuario[2][0] = 0;
        escalonaDoUsuario[2][1] = 0;
        escalonaDoUsuario[2][2] = 1;

        rotacionaDoUsuario[0][0] = cos(anguloEmRadianos);
        rotacionaDoUsuario[0][1] = sin(anguloEmRadianos);
        rotacionaDoUsuario[0][2] = 0;
        rotacionaDoUsuario[1][0] = -sin(anguloEmRadianos);
        rotacionaDoUsuario[1][1] = cos(anguloEmRadianos);
        rotacionaDoUsuario[1][2] = 0;
        rotacionaDoUsuario[2][0] = 0;
        rotacionaDoUsuario[2][1] = 0;
        rotacionaDoUsuario[2][2] = 1;

        transladaDoUsuario[0][0] = 1;
        transladaDoUsuario[0][1] = 0;
        transladaDoUsuario[0][2] = 0;
        transladaDoUsuario[1][0] = 0;
        transladaDoUsuario[1][1] = 1;
        transladaDoUsuario[1][2] = 0;
        transladaDoUsuario[2][0] = dx;
        transladaDoUsuario[2][1] = dy;
        transladaDoUsuario[2][2] = 1;

        transladaParaOrigemPoligono[0][0] = 1;
        transladaParaOrigemPoligono[0][1] = 0;
        transladaParaOrigemPoligono[0][2] = 0;
        transladaParaOrigemPoligono[1][0] = 0;
        transladaParaOrigemPoligono[1][1] = 1;
        transladaParaOrigemPoligono[1][2] = 0;
        transladaParaOrigemPoligono[2][0] = pontoCentroPoligono.x;
        transladaParaOrigemPoligono[2][1] = pontoCentroPoligono.y;
        transladaParaOrigemPoligono[2][2] = 1;

        matrizAuxiliar[0][0] = 1;
        matrizAuxiliar[0][1] = 0;
        matrizAuxiliar[0][2] = 0;
        matrizAuxiliar[1][0] = 0;
        matrizAuxiliar[1][1] = 1;
        matrizAuxiliar[1][2] = 0;
        matrizAuxiliar[2][0] = 0;
        matrizAuxiliar[2][1] = 0;
        matrizAuxiliar[2][2] = 1;

        for(unsigned int i=0; i<3; i++)
	{
		for(unsigned int j=0; j<3; j++)
		{
			for(unsigned int k=0; k<3; k++)
			{
				soma += matrizAuxiliar[i][k] *
                                        transladaParaMeioDoMundo[k][j];
			}
			matrizFinal[i][j] = soma;
			soma = 0;
		}
	}
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        matrizAuxiliar[i][j] = matrizFinal[i][j];
                }
        }
        if(transladaBool){
                for(unsigned int i=0; i<3; i++)
	        {
		        for(unsigned int j=0; j<3; j++)
		        {
			        for(unsigned int k=0; k<3; k++)
			        {
				        soma += matrizAuxiliar[i][k] *
                                                transladaDoUsuario[k][j];
			        }
			        matrizFinal[i][j] = soma;
			        soma = 0;
		        }
	        }
        }   
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        matrizAuxiliar[i][j] = matrizFinal[i][j];
                }
        }
        if(escalonaBool){
                for(unsigned int i=0; i<3; i++)
	        {
		        for(unsigned int j=0; j<3; j++)
		        {
			        for(unsigned int k=0; k<3; k++)
			        {
				        soma += matrizAuxiliar[i][k] *
                                                escalonaDoUsuario[k][j];
			        }
			        matrizFinal[i][j] = soma;
			        soma = 0;
		        }
	        }
        }   
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        matrizAuxiliar[i][j] = matrizFinal[i][j];
                }
        }
        if(rotacionaBool){
                for(unsigned int i=0; i<3; i++)
	        {
		        for(unsigned int j=0; j<3; j++)
		        {
			        for(unsigned int k=0; k<3; k++)
			        {
				        soma += matrizAuxiliar[i][k] *
                                                rotacionaDoUsuario[k][j];
			        }
			        matrizFinal[i][j] = soma;
			        soma = 0;
		        }
	        }
        }    
        for( unsigned int i = 0; i < 3; i++){
                for(unsigned int j = 0; j <3; j++){
                        matrizAuxiliar[i][j] = matrizFinal[i][j];
                }
        }
        for(unsigned int i=0; i<3; i++)
	{
		for(unsigned int j=0; j<3; j++)
		{
			for(unsigned int k=0; k<3; k++)
			{
				soma += matrizAuxiliar[i][k] *
                                        transladaParaOrigemPoligono[k][j];
			}
			matrizFinal[i][j] = soma;
			soma = 0;
		}
	}

        for(unsigned int i = 0; i < pontos.size(); i++){
                pontos[i].Homogeneo(matrizFinal);
        }
};

#pragma package(smart_init)
