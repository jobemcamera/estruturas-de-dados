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
  delete [] vertices;

  for (int i = 0; i < maxVertices; i++)
  {
    delete [] matrizAdjacencias[i]; // vetores linha
  }
  delete [] matrizAdjacencias;
}

int Grafo::obterIndice(TipoItem item) {}

bool Grafo::estaCheio() {}

void Grafo::insereVertice(TipoItem item) {}

void Grafo::insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso) {}

int Grafo::obterPeso(TipoItem noSaida, TipoItem noEntrada) {}

int Grafo::obterGrau(TipoItem item) {}

void Grafo::imprimirMatriz() {}

void Grafo::imprimirVertice() {}
