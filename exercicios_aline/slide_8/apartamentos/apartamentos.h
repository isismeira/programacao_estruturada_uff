typedef struct apartamento Apartamento;

Apartamento* cria_vetor_apartamentos(int qtd);
void le_dados_apartamentos(Apartamento* apts, int qtd);
float calcula_area_total(Apartamento* apts, int qtd);
void calcula_valores(Apartamento* apts, int qtd, float despesa_total);
void imprime_apartamento_maior_moradores(Apartamento* apts, int qtd);
void libera_apartamentos(Apartamento* apts);

