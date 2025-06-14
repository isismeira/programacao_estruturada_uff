typedef struct vetor Vetor;

Vetor* cria_vetor(int len);
void preenche_vetor(Vetor* v, float* valores);
float acessar_elemento(Vetor* v, int i);
void soma_vetores(Vetor* v1, Vetor* v2, Vetor* v3);
void multiplica_vetores(Vetor* v1, Vetor* v2, Vetor* v3);
void mult_escalar_vetor(Vetor* v, float k);
void free_vetor(Vetor* v);
