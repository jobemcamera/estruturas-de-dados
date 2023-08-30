// Grafo Não-Direcionado Ponderado
#include <iostream>
using namespace std;

typedef string TipoItem;

class Grafo
{
private:
  int arestaNula; // ausencia de aresta (nao confundir com 0 do peso)
  int maxVertices;
  int numVertices;
  TipoItem *vertices;      // vetor dinamico
  int **matrizAdjacencias; // vetor de vetores do tipo int (matriz)

public:
  Grafo(int max, int valorArestaNula);
  ~Grafo();
  int obterIndice(TipoItem item);
  bool estaCheio();
  void insereVertice(TipoItem item);
  void insereAresta(TipoItem noSaida, TipoItem noEntrada, int peso);
  int obterPeso(TipoItem noSaida, TipoItem noEntrada);
  int obterGrau(TipoItem item);
  void imprimirMatriz();
  void imprimirVertice();
};