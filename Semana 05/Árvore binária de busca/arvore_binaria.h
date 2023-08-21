#include <iostream>
#include "aluno.h"

struct No
{
  Aluno aluno; // informação = objeto Aluno
  No *filho_esquerda;
  No *filho_direita;
};

// BST = Binary Search Tree
class ArvoreBinariaBusca
{
private:
  No *raiz;

public:
  ArvoreBinariaBusca();
  ~ArvoreBinariaBusca();
  void deletarArvore(No *NoAtual); // chamar deletarArvore dentro do destrutor
  No *obterRaiz();
  bool estaVazio();
  bool estaCheio();
  void inserir(Aluno aluno);
  void remover(Aluno aluno);
  void buscar(Aluno &aluno, bool &busca);
  void imprimirPreOrdem(No *NoAtual);
  void imprimirEmOrdem(No *NoAtual);
  void imprimirPosOrdem(No *NoAtual);
};