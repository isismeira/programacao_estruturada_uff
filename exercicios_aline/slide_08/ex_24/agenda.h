// TAD: Agenda de Contatos
typedef struct pessoa Pessoa;

// Funções exportadas 
Pessoa* agenda_cria();
void agenda_libera(Pessoa* p);
void agenda_atribui(Pessoa* p, char nome[], char email[], char rua[], int numero, 
                     char complemento[], char bairro[], char cep[], char cidade[], 
                     char estado[], char pais[], int ddd, char telefone[], 
                     int dia, int mes, int ano, char obs[]);

void agenda_acessa(Pessoa* p);

int compara_nome(Pessoa* p, char nome[]);
int verifica_mes(Pessoa* p, int mes);
int verifica_dia_mes(Pessoa* p, int dia, int mes);

void imprime_resumido(Pessoa* p);
void imprime_completo(Pessoa* p);
