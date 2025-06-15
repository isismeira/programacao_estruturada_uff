typedef struct string String;

String* cria_string(char* string);
char* inverte_string(String* s);
int eh_palindromo(String* s) ;
char* prefixo_string(String* s, int pos_max);
char* sufixo_string(String* s, int pos_min);
char* troca_letra(String* s, char letra_original, char letra_substituta);
void libera_string(String* s);