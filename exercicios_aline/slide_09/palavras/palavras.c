#include <stdio.h>
#include <stdlib.h>
#include "palavras.h"

typedef struct palavra {
    char palavra[30];
    int qtd;
} Palavra;

typedef struct el_palavra {
    Palavra* pl;
    struct el_palavra* prox;
}ElementoPalavra;

typedef struct palavras {
    ElementoPalavra* inicio;
}ListaPalavras;

ListaPalavras* criar () {
    ListaPalavras * lp = ( ListaPalavras *) malloc ( sizeof ( ListaPalavras ) ) ;
    lp->inicio = NULL ;
    return lp ;
}

// Questão 1) 
ElementoPalavra* ep_criar() {
    return NULL;
}

ElementoPalavra* insere_elemento_final(ElementoPalavra* ep, Palavra *p) {
    ElementoPalavra* novo = (ElementoPalavra*)malloc(sizeof(ElementoPalavra));
    novo->pl = p;
    novo->prox = NULL;

    ElementoPalavra* percorre = ep;
    ElementoPalavra* ultimo = NULL;

    while (percorre!=NULL) {
        ultimo = percorre;
        percorre = percorre->prox;
    }

    ultimo->prox = novo;
    return ep;
}

ListaPalavras* ler_com_duplicado(char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    int primeira_palavra = 1;
    ListaPalavras* lp = criar(); // ❌ char *lp = criar()
    ElementoPalavra* ep = ep_criar(); // ❌ char *lp = criar()
    while (1) {
        char palavra_texto[30];

        if (fscanf(arquivo, "%[^ ]", palavra_texto) != 1) break;

        Palavra* p = (Palavra*)malloc(sizeof(Palavra));
        strcpy(p->palavra, palavra_texto);
        p->qtd = 1;

        ep = insere_elemento_final(ep, p);

        if (primeira_palavra) {
            lp->inicio = ep; //❌ lp->inicio = p
            primeira_palavra = 0;
        }
    }
    fclose(arquivo); // !!! Linha ausente
    return lp;
}


// Questão 2) 
ListaPalavras* ler_sem_duplicado(char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    int primeira_palavra = 1;
    char palavras[100][30];
    int qtdd_palavras = 0;
    ListaPalavras* lp = criar(); // ❌ char *lp = criar()
    ElementoPalavra* ep = ep_criar(); // ❌ char *lp = criar()
    while (1) {
        char palavra_texto[30];
        int palavra_repetida = 0;

        if (fscanf(arquivo, "%[^ ]", palavra_texto) != 1) break;

        for (int i = 0; i < qtdd_palavras; i++) {
            if (strcmp(palavras[i], palavra_texto) == 0) {
                palavra_repetida = 1;
                break;
            }
        }

        if (!palavra_repetida) {
            Palavra* p = (Palavra*)malloc(sizeof(Palavra));
            strcpy(p->palavra, palavra_texto);
            strcpy(palavras[qtdd_palavras], palavra_texto); //❌ strcpy(palavras, palavra_texto);
 
            p->qtd = 1;

            ep = insere_elemento_final(ep, p);

            if (primeira_palavra) {
                lp->inicio = ep; //❌ lp->inicio = p
                primeira_palavra = 0;
            }

            qtdd_palavras++;

        } else {
            ElementoPalavra* p = ep;
            for (p; p!= NULL; p->prox) {
                if (strcmp(p->pl->palavra, palavra_texto) == 0){ // ❌ (p->pl->palavra == palavra_texto)
                    p->pl->qtd++;
                    break;
                }
            }
        }   
    }
    fclose(arquivo); // !!! Linha ausente  
    return lp;
}

// Questão 4)
ListaPalavras* remover(ListaPalavras * ps , char * palavra ) {
    ElementoPalavra* p = ps->inicio; // ❌ ElementoPalavra* p = ps;
    ElementoPalavra* ant = NULL; 
    while (p!=NULL && strcmp(p->pl->palavra, palavra) != 0 ) { // ❌ (p->pl->palavra != palavra_texto)
        ant = p;
        p = p->prox;
    } 
    if (ant == NULL) {
        if (p->pl->qtd > 1) {
            p->pl->qtd--;
        } else {
            ps->inicio = p->prox; // ❌ ps = p->prox 
        }
    } else {
        if (p->pl->qtd > 1) {
            p->pl->qtd--;
        } else {
            ant->prox = p->prox;
        }
    }
    free(p->pl); // !!! Linha ausente
    free(p);
    return ps;
}

// Questão 5)
void liberar ( ListaPalavras * ps ) {
    ElementoPalavra *p = ps->inicio; //❌ ElementoPalavra* p = ps
    while (p != NULL) {
        ElementoPalavra *temp = p->prox;
        free(p->pl); // !!! Linha ausente
        free(p);
        p=temp;
    }
    free(ps);
}


// Questão 3)
int contar_elementos(ElementoPalavra* ep) {
    int cont = 0;
    while (ep != NULL) {
        cont++;
        ep = ep->prox;
    }
    return cont;
}

ElementoPalavra** lista_para_vetor(ElementoPalavra* ep, int n) {
    ElementoPalavra** vetor = (ElementoPalavra**)malloc(n * sizeof(ElementoPalavra*));
    for (int i = 0; i < n; i++) {
        vetor[i] = ep;
        ep = ep->prox;
    }
    return vetor;
}

ElementoPalavra* vetor_para_lista(ElementoPalavra** vetor, int n) {
    for (int i = 0; i < n - 1; i++) {
        vetor[i]->prox = vetor[i + 1];
    }
    vetor[n - 1]->prox = NULL;
    return vetor[0];
}

int particiona(ElementoPalavra** v, int ini, int fim) {
    int pivo = v[fim]->pl->qtd;
    int i = ini - 1;
    for (int j = ini; j < fim; j++) {
        if (v[j]->pl->qtd > pivo) { // ordem decrescente
            i++;
            ElementoPalavra* temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    ElementoPalavra* temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;
    return i + 1;
}

void quicksort(ElementoPalavra** v, int ini, int fim) {
    if (ini < fim) {
        int p = particiona(v, ini, fim);
        quicksort(v, ini, p - 1);
        quicksort(v, p + 1, fim);
    }
}

ListaPalavras* ordenar(ListaPalavras* ps) {
    int n = contar_elementos(ps->inicio);
    if (n <= 1) return ps;

    ElementoPalavra** vetor = lista_para_vetor(ps->inicio, n);
    quicksort(vetor, 0, n - 1);
    ps->inicio = vetor_para_lista(vetor, n);
    free(vetor);

    return ps;
}
