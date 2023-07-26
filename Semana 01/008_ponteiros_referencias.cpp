// Ponteiro é uma variável cujo conteúdo é um endereço de memória, não um valor no sentido tradicional
// O endereço de uma variável (ou função) é a localização na memória do primeiro byte ocupado por ela
// Alocação estática e dinâmica de memória
// Alocou com new, desaloque com delete

// Declarando variáveis
// int alpha;
// int *intPointer;

// Inicializando ponteiro: intPointer aponta para alpha
// intPointer = &alpha;

// Alocação dinâmica
// int *intPointer;
// intPointer = new int;

// int anotherInt;
// Para obter o conteúdo que está localizado no endereço apontado por intPointer
// anotherInt = *intPointer;
// Para alterar o conteúdo que está localizado no endereço apontado por intPointer
// *intPointer = 25;

// Um ponteiro com valor 0 (zero), por definição, aponta para vazio
#include <cstddef>
bool *truth = NULL;
float *money = NULL;
int alpha;
int *intPointer;
int anotherInt;

int main()
{
  intPointer = new int;
  anotherInt = *intPointer;
  *intPointer = 25;
  delete intPointer;
  intPointer = NULL; // Opcional, mas uma boa prática para evitar ponteiros soltos.
  
  return 0;
}