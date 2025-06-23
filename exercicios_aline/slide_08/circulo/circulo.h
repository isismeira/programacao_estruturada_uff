typedef struct circulo Circulo;

Circulo* cria_circulo(float x, float y, float raio);

void acessa_circulo (Circulo* c, float* x, float* y, float* raio);

void atribui_circulo (Circulo* c, float x, float y, float raio);

void libera_circulo(Circulo* c);

float area_circulo(Circulo* c);

int dentro_circulo(Circulo* c, float x_novo, float y_novo);