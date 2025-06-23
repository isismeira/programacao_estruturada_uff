# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "amino.h"

// Questão 1)
typedef struct aminoacido {
    int polaridade;
    int essencial;
    char* nome;
    int massa;
}Aminoacido;

Aminoacido* criar_amino(int polaridade, int essencial, char* nome, float massa) {
    Aminoacido* a = (Aminoacido*)malloc(sizeof(Aminoacido));
    if (a == NULL) {
        printf("Memória insuficiente");
        exit(1);
    }

    a->polaridade = polaridade;
    a->essencial = essencial;
    a->nome = strdup(nome);
    a->massa = massa;

    return a;
}

void liberar_amino(Aminoacido* amin) {
    free(amin->nome); // !!!
    free(amin);
}

// Questão 2)
typedef struct cadeia_amino {
    Aminoacido* info; // !!!
    struct lista* prox;
}Cadeia;


Cadeia* criar_cadeia() {
    return NULL;
}

void liberar_cadeia(Cadeia* c) {
    Cadeia* p = c;
    while (p!=NULL) {
        Cadeia* t = p->prox;
        liberar_amino(p->info); //!!! liberar o aminoácido também
        free(p);
        p = t;
    }
}

// Questão 3)
int somar_massas(Cadeia* ca) {
    if (ca == NULL) {
        return 0;
    }
    return ca->info->massa + somar_massas(ca->prox);
}

int eh_proteina(Cadeia* ca) {
    return somar_massas(ca) > 10000;
}

// Questão 4)
Cadeia* transformar_proteina(Cadeia* protein) {
    Cadeia* p = protein;
    int soma_massas = somar_massas(p);
    while (soma_massas > 10000) {
        int menor_massa = retorna_menor_massa(p);
        p = remove_valor(p, menor_massa);
        soma_massas = somar_massas(p);
    }
    return protein;
}

int retorna_menor_massa(Cadeia* protein) {
    if (protein == NULL) return 0; // !!!

    Cadeia* p = protein;
    int menor_massa = p->info->massa;
    for (p; p != NULL; p = p->prox) {
        if ((p->info->massa) < menor_massa) {
            menor_massa = (p->info->massa);
        } 
    }
    return menor_massa;
}

Cadeia* remove_valor(Cadeia* protein, int valor) {
    Cadeia* ant = NULL;
    Cadeia* p = protein;
	while (p != NULL && p->info->massa != valor) { // !!!	
		ant = p;					
		p = p->prox; 
	}
	if (p == NULL)					
		return protein;					
	if (ant == NULL)					
		protein = p->prox; 			
	else 
		ant->prox = p->prox; 			
	free(p);					
	return protein;	    
}


// Questão 5)

Cadeia* adicionar_nao_essencial(Cadeia* ca1, Cadeia* ca2) {
    Cadeia* c_um = ca1;
    Cadeia* c_dois = ca2;

    for (c_dois; c_dois != NULL; c_dois = c_dois->prox) {
        if (c_dois->info->nome = "essencial") {
            return insere_depois_apolar(c_um, c_dois->info);
        }
    }

    return NULL;
}

Cadeia* insere_depois_apolar(Cadeia* ca1, Aminoacido* a) {
    Cadeia* c_um = ca1;
    Aminoacido* a = a;

    int achou = 0;
    for (c_um; c_um != NULL; c_um = c_um->prox) {
        if (c_um->info->polaridade == 0) {
            Cadeia* novo = malloc(sizeof(Cadeia));
            novo->info = a;
            novo->prox = c_um->prox;
            c_um->prox = novo;
            achou = 1;
            break;
        }
    }

    if ( achou == 0 ) {
        Cadeia* novo = (Cadeia*)malloc(sizeof(Cadeia));
        novo->info = a;	
        novo->prox = ca1;			
        return novo; 
    }

    return ca1;
}