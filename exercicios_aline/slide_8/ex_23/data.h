// TAD: Data (dia, mes, ano)
typedef struct dma Data;

// Funções exportadas 
Data* data_cria(int dia, int mes, int ano);
void data_libera(Data* d);
void data_acessa(Data* d, int* dia, int* mes, int* ano);
void data_atribui(Data* d, int dia, int mes, int ano);
int data_diferenca(Data* d1, Data* d2);