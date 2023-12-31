#include <iostream>
#include "grafo.h"
using namespace std;

Grafo::Grafo(int max, int valorArestaNula) // construtor
{
  arestaNula = 0;
  maxVertices = max;
  numVertices = valorArestaNula;

  vertices = new TipoItem[maxVertices];

  matrizAdjacencias = new int *[maxVertices]; // vetor de vetores de inteiros
  for (int i = 0; i < maxVertices; i++)
  {
    matrizAdjacencias[i] = new int[maxVertices];
  }

  for (int i = 0; i < maxVertices; i++) // linha
  {
    for (int j = 0; j < maxVertices; j++) // coluna
    {
      matrizAdjacencias[i][j] = arestaNula;
    }
  }
}

Grafo::~Grafo() // destrutor
{
  delete[] vertices;

  for (int i = 0; i < maxVertices; i++)
  {
    delete[] matrizAdjacencias[i]; // vetores linha
  }
  delete[] matrizAdjacencias;
}

int Grafo::obterIndice(TipoItem item)
{
  int indice = 0;

  while (item != vertices[indice])
  {
    indice++;
  }

  if (item == vertices[indice])
  {
    return indice;
  }
  else
  {
    return -1;
  }
}

bool Grafo::estaCheio()
{
  return (numVertices == maxVertices);
}

void Grafo::insereVertice(TipoItem item)
{
  if (estaCheio())
  {
    cout << "O numero maximo de vertices foi alcancado\n";
  }
  else
  {
    vertices[numVertices] = item;
    numVertices++;
  }
}

void Grafo::insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso)
{
  int linha = obterIndice(noSaida);
  int coluna = obterIndice(noEntrada);

  if (linha == -1 || coluna == -1)
  {
    cout << "Voce ainda nao inseriu esse vertice! Insira-o antes!\n";

    return;
  }

  matrizAdjacencias[linha][coluna] = peso;
  matrizAdjacencias[coluna][linha] = peso; // remover se for grafo direcionado
}

int Grafo::obterPeso(TipoItem noSaida, TipoItem noEntrada)
{
  int linha = obterIndice(noSaida);
  int coluna = obterIndice(noEntrada);

  if (linha == -1 || coluna == -1)
  {
    cout << "Voce ainda nao inseriu esse vertice! Insira-o antes!\n";

    return -1;
  }

  return (matrizAdjacencias[linha][coluna]);
}

int Grafo::obterGrau(TipoItem item)
{
  int linha = obterIndice(item);
  int grau = 0;

  if (linha == -1)
  {
    cout << "Voce ainda nao inseriu esse vertice! Insira-o antes!\n";

    return -1;
  }

  for (int i = 0; i < maxVertices; i++)
  {
    if (matrizAdjacencias[linha][i] != arestaNula)
    {
      grau++;
    }
  }

  return grau;
}

void Grafo::imprimirMatriz()
{
  cout << "Matriz de adjacencia:\n";
  for (int i = 0; i < maxVertices; i++)
  {
    for (int j = 0; j < maxVertices; j++)
    {
      cout << matrizAdjacencias[i][j] << " ";
    }
    cout << endl;
  }
}

void Grafo::imprimirVertice()
{
  cout << "Lista de vertices::\n";
   for (int i = 0; i < numVertices; i++)
  {
    cout << i << ": " << vertices[i] << endl;
  }
}
