// Alocação diâmica
// Passagem de parâmetros

// Vetores são a maneira mais simples de estruturarmos um conjunto de dados
// Elementos ocupam regiões consecutivas de memória

#include <iostream>
using namespace std;

int main()
{
  int c[10] = {0};         // Inicializando o array c com todos os elementos igual a 0
  int d[10] = {14, 0, 13}; // o restante dos valores serão preenchidos com 0 (zero)
  int e[10] = {0};         // Inicializando o array e com todos os elementos igual a 0

  // inserindo diretamente na posição
  // c[5] = 30;
  // c[7] = 40;
  // c[8] = 50;

  // inserindo com for
  for (int i = 0; i < 10; i++)
  {
    cout << "c[" << i << "] " << c[i] << "\n";
  }

  int num_elem = 10;
  int *vetor = new int[num_elem]; // alocando em tempo de execução (dinâmico)

  for (int j = 0; j < (num_elem); j++)
  {
    vetor[j] = 2 * j;
  }
  for (int k = 0; k < (num_elem); k++)
  {
    cout <<  "vetor [" << k << "] = " << vetor[k] << "\n";
  }

  delete[] vetor; // desalocando 

  return 0;
}

