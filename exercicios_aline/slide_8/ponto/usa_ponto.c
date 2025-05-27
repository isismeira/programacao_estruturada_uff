// programa cliente da TAD ponto

#include "ponto.h"
#include <stdio.h>

int main (){
	//float x, y;
	Ponto* p = pto_cria(2.0,1.0);
	Ponto* q = pto_cria(3.4,2.1);
	float d = pto_distancia(p,q);
	printf("Distancia entre pontos: %f\n",d);

	pto_atribui(p, 4.0, 1.0);
	d = pto_distancia(p,q);
	printf("Distancia entre pontos: %f\n",d);


	pto_libera(q);
	pto_libera(p);
	return 0;
}