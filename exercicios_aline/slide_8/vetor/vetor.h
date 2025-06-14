typedef struct vetor Vetor;

Vetor* cria_vetor(int len);
void acessa_vetor(Vetor* v, int posicao, float* valor);
void atribui_vetor(Vetor* v, int posicao, float valor);
void libera_vetor(Vetor* v);
void preenche_vetor(Vetor* v, float* valores);
void soma_vetor(Vetor* v);
float menor_elemento_vetor(Vetor* v);
float maior_elemento_vetor(Vetor* v);
int vetor_busca(Vetor* v, float elemento);