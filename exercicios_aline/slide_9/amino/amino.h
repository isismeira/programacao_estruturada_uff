typedef struct aminoacido Aminoacido;

typedef struct cadeia_amino Cadeia;

Aminoacido* criar_amino(int polaridade, int essencial, char* nome, float massa);

void liberar_amino(Aminoacido* amin);

Cadeia* criar_cadeia();

void liberar_cadeia(Cadeia* ca);

int eh_proteina(Cadeia* ca);

int somar_massas(Cadeia* ca);

Cadeia* transformar_proteina(Cadeia* protein);

int retorna_menor_massa(Cadeia* protein);

Cadeia* remove_valor(Cadeia* protein, int valor);

Cadeia* adicionar_nao_essencial(Cadeia* ca1, Cadeia* ca2);

Cadeia* insere_depois_apolar(Cadeia* ca1, Aminoacido* a);

Cadeia* inserir_amino(Cadeia* ca, Aminoacido* am);

